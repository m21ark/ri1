#!/usr/bin/env python3
import rclpy
import time
import numpy as np
from rclpy.node import Node
from geometry_msgs.msg import Twist, Pose2D
from sensor_msgs.msg import LaserScan 
from nav_msgs.msg import Odometry
from nav_msgs.srv import GetMap
from flatland_msgs.msg import Collisions
from flatland_msgs.srv import MoveModel
from robots.params import *
import os

class GenericController(Node):
    
    def __init__(self, robot_name):
        super().__init__(robot_name)

        # Logging variables
        self. startTime = time.time()
        self.startPos = None
        self.distances_to_wall = []
        self.num_collisions = 0
        self.velocities = []
        self.pos_path = []
        
        # R2 exclusive variables
        self.isFollowingRobot = False
        self.isFollowingStartPos = None
        self.isFollowingStartTime = None
        
        # Reactive behavior variables 
        self.rays_walls = []
        self.rays_r1 = []
        
        self.speed_multiplier = 1 # Default speed multiplier (for R1)
        
        if STATISTIC_ANALYSIS:
            # if folder "logs" does not exist, create it
            if not os.path.exists('logs'):
                os.makedirs('logs')
                
            self.stats_file = open(f'logs/log_{robot_name}.txt', 'w')


    def stop(self):
        log('Stopping the robot')
        self.pub_vel(0.0, 0.0)
        exit(0)

    def move_model(self, model_name, x, y, theta):
        client = self.create_client(MoveModel, "/move_model")
        client.wait_for_service()
        request = MoveModel.Request()
        request.name = model_name
        request.pose = Pose2D()
        request.pose.x = x
        request.pose.y = y
        request.pose.theta = theta
        client.call_async(request)

    def get_map(self):
        client = self.create_client(GetMap, "/map_server/map")
        client.wait_for_service()
        request = GetMap.Request()
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()

    def set_model_random_position(self, model_name):
        map_data = self.get_map()
        map_width = map_data.map.info.width
        map_height = map_data.map.info.height
        map_resolution = map_data.map.info.resolution
        map_origin = map_data.map.info.origin

        log(f'Map width: {map_width}, height: {map_height}, resolution: {map_resolution}, origin: {map_origin}')
        # Generate a random position within the map, but check if it's not occupied by a wall
        while True:
            if RANDOM_START_IS_RECTANGLE:
                # Generate a random position within a rectangle in the map
                if model_name == 'robot1':
                    x = np.random.uniform(map_origin.position.x + 2, map_origin.position.x + 3)
                    y = np.random.uniform(map_origin.position.y + 10.5, map_origin.position.y + map_height * map_resolution - 10.5)
                elif model_name == 'robot2':
                    x = np.random.uniform(map_origin.position.x + 5, map_origin.position.x + map_width * map_resolution - 5)
                    y = np.random.uniform(map_origin.position.y + 7.5, map_origin.position.y + 8)

            else:
                # Generate a random position around the center of the robots spawn
                radius = np.random.uniform(0, 1)
                angle = np.random.uniform(0, 2 * np.pi)

                pos_x = 0
                pos_y = 0

                if model_name == 'robot1':
                    pos_x = -11
                elif model_name == 'robot2':
                    pos_y = -3
                
                x = pos_x + radius * np.cos(angle)
                y = pos_y + radius * np.sin(angle)
                
            theta = np.random.uniform(-np.pi, np.pi)
            map_x = int((x - map_origin.position.x) / map_resolution)
            map_y = int((y - map_origin.position.y) / map_resolution)
            
            if map_data.map.data[map_y * map_width + map_x] == 0:
                break


        self.move_model(model_name, x, y, theta)
        log(f'Set random position for {model_name} at ({x:.2f}, {y:.2f}, {theta:.2f})')
        
    def pub_vel(self, linear, angular):
        msg = Twist()
        msg.linear.x = float(linear) * self.speed_multiplier
        msg.angular.z = float(angular) * self.speed_multiplier
        self.vel_pub.publish(msg)
        
    def angle_from_index(self, index):
        num_rays = len(self.rays_r1)
        angle_per_ray = 360 / num_rays
        angle_deg = (index - num_rays // 2) * angle_per_ray
        angle_rad = np.deg2rad(angle_deg)
        return angle_rad
    
    def handle_odom(self, data: Odometry):

        # Extract the linear velocity and store it
        vel_x = data.twist.twist.linear.x
        vel_y = data.twist.twist.linear.y
        curr_vel = math.sqrt(math.pow(vel_x, 2) + math.pow(vel_y, 2))
        self.velocities.append(curr_vel)
        
        # Extract the position and store it
        position = data.pose.pose.position
        self.pos_path.append((round(position.x,3), round(position.y,3)))
        
        if self.isFollowingRobot and self.isFollowingStartPos == None:
            self.isFollowingStartTime = time.time() - self.startTime
            self.isFollowingStartPos = (round(data.pose.pose.position.x, 2), round(data.pose.pose.position.y, 2)) 
        
        self.handle_position_data(round(position.x, 2), round(position.y, 2))
        
    def handle_position_data(self, posX, posY):
        
        # If the start position is not set, set it
        if self.startPos == None:
            self.startPos = (posX, posY)
            print(f'[Start Position]: {self.startPos}')
        
        # If the robot is following the start position, check if it's at the end
        else:
            
            # Check if the robot has reached the end position within a specific radius
            hasEndedPath: bool = False
            if time.time() - self.startTime > 15: # Wait for 15 seconds before checking the end position to avoid false positives
                distanceToEnd = math.sqrt(math.pow(posX - self.startPos[0], 2) + math.pow(posY - self.startPos[1], 2))
                if distanceToEnd < FINISH_DISTANCE_RANGE:
                    hasEndedPath = True
            
            # If the robot has reached the end position, stop the robot and save the stats if needed
            if hasEndedPath and STATISTIC_ANALYSIS:
                self.save_stats_to_file(posX, posY)
                self.stop()
                
    def save_stats_to_file(self, posX, posY):
        # reduce the self.pos_path to take 1000 points at most, distributed evenly
        if len(self.pos_path) > 1000:
            self.pos_path = self.pos_path[::len(self.pos_path) // 1000]
        
        self.stats_file.write(f'[Start Position]: {self.startPos}\n')
        self.stats_file.write(f'[End Position]: {(posX, posY)}\n')
        self.stats_file.write(f'[Number of Collisions]: {self.num_collisions}\n')
        self.stats_file.write(f'[Average Velocity]: {sum(self.velocities) / len(self.velocities):.2f}\n')
        self.stats_file.write(f'[Average Distance to Wall]: {sum(self.distances_to_wall) / len(self.distances_to_wall):.2f}\n')
        self.stats_file.write(f'[Correct % Distance to Wall]: {len([x for x in self.distances_to_wall if x < IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE and x > IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE]) / len(self.distances_to_wall) * 100:.2f}%\n')
        self.stats_file.write(f'[Time Taken]: {time.time() - self.startTime:.2f} seconds\n')
        self.stats_file.write(f'[Path]: {self.pos_path}\n')
        if self.isFollowingStartPos:
            self.stats_file.write(f'[Started Following Time]: {self.isFollowingStartTime:.2f} seconds\n')
            self.stats_file.write(f'[Started Following Pos]: {self.isFollowingStartPos}\n')
        self.stats_file.close()
        
    def handle_collision(self, msg: Collisions):
        if len(msg.collisions):
            self.num_collisions += 1
            log(f'[Collision Detected] {self.num_collisions} times')
            
            if STOP_IF_COLLISION:
                self.stop()
            
    def parse_laser_wall_data(self):
        
        # We'll follow the wall on the right-hand side
        
        front_index = len(self.rays_walls) // 2  # Front of the robot
        right_index = len(self.rays_walls) // 4  # Right side of the robot
        right_front_index = len(self.rays_walls) // 3  # Forward-right to detect upcoming curves

        front_distance = self.rays_walls[front_index]
        right_distance = self.rays_walls[right_index]
        right_front_distance = self.rays_walls[right_front_index]
        
        if right_distance != float('inf'):
            self.distances_to_wall.append(right_distance)
            
        return front_distance, right_distance, right_front_distance
    
    def handle_laser_wall(self, msg: LaserScan):
        # Replace NaN values with infinity and store the data
        self.rays_walls = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        
    def follow_wall(self, F_D, R_D, RF_D):
        self.isFollowingRobot = False
        
        # Initialize the log message
        log_sms = f"[S] F_D: {F_D:4.2f}, R_D: {R_D:4.2f}, RF_D: {RF_D:4.2}. "
        linear_vel, angular_vel = 0.0, 0.0  # Default values
        log_action = ''  # Action message to log

        # ====================== High-priority cases ======================

        # Condition 1: If there is an obstacle directly in front, stop and turn left to avoid collision
        if F_D < IDEAL_DISTANCE:
            log_action = 'Obstacle detected in front, turning left to avoid collision.'
            angular_vel = ANG_VEL_MAX  # Full left turn
            linear_vel = 0.0  # Stop forward movement
            
        # Condition 2: If no wall is detected on the right, turn right in-place to find the wall
        elif R_D == float('inf'):
            log_action = 'No wall detected on the right, turning right to find the wall.'
            angular_vel = -ANG_VEL_MAX
            linear_vel = 0.0
            
        # ====================== Wall-following cases ======================

        # Condition 3: Detecting a curve to the right
        elif RF_D < R_D:
            log_action = 'Detected curve to the right, turning left to follow curve.'
            angular_vel = clamp((R_D - RF_D), ANG_VEL_MAX)  # Turn left with force based on difference
            linear_vel = 0.7 * LIN_VEL_MAX  # Slow down slightly during curve following

        # Condition 4: Too far from the wall on the right, turn right to get closer
        elif R_D > IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too far from the wall, turning right.'
            angular_vel = -clamp((R_D - IDEAL_DISTANCE), ANG_VEL_MAX)  # Turn right, force based on how far
            linear_vel = 0.5 * LIN_VEL_MAX  # Slow down while correcting distance

        # Condition 5: Too close to the wall on the right, turn left to move away
        elif R_D < IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too close to the wall, turning left.'
            angular_vel = clamp((IDEAL_DISTANCE - R_D), ANG_VEL_MAX)  # Turn left, proportionate to closeness
            linear_vel = 0.5 * LIN_VEL_MAX  # Slow down while correcting

        # ====================== Default case: ideal distance ======================
        
        else:
            # At ideal distance, make slight adjustments to maintain the distance
            angular_correction = 0.7 * (IDEAL_DISTANCE - R_D)  # Small correction for wall-following
            angular_vel = 5 * clamp(angular_correction, ANG_VEL_MAX)
            linear_vel = LIN_VEL_MAX  # Move forward at ideal speed
            log_action = f'At ideal distance, making slight adjustments. Ang Corr: {angular_correction:4.2f}'

        # Log the action and return the velocities
        log_sms += f'{log_action:<50}'
        log(log_sms)
        
        return linear_vel, angular_vel
    
    def follow_wall_PD(self, F_D, R_D, RF_D):
        self.isFollowingRobot = False
        
        front_index = len(self.rays_walls) // 2  # Front of the robot
        
        # collect all rays between the front and right side of the robot and average them, if they are not inf
        right_distances = [x for x in self.rays_walls[0:front_index + 1] if x != float('inf')]
        right_sector_dist = sum(right_distances) / len(right_distances) if len(right_distances) > 0 else float('inf')
        
        if right_sector_dist == float('inf'):
            return 0.0, ANG_VEL_MAX # Rotate left in place to find the wall

        # Calculate the error as the difference between current right distance and ideal distance
        error = abs(IDEAL_DISTANCE - right_sector_dist)
        
        # Calculate the derivative of the error (rate of change)
        if hasattr(self, 'last_error'):
            derivative = (error - self.last_error) / (time.time() - self.last_time)
        else:
            derivative = 0.0

        control = Kp * error + Kd * derivative

        # PD control for angular velocity
        angular_vel = -clamp(control, ANG_VEL_MAX)
        
        # Linear velocity based on front distance (slow down if too close to an obstacle)
        if F_D < IDEAL_DISTANCE or RF_D < IDEAL_DISTANCE:
            dist = min((F_D), (RF_D))
            linear_vel = LIN_VEL_MAX * clamp(1 - 1 / dist, 1)
            angular_vel = ANG_VEL_MAX  # Turn left to avoid collision
        else:
            linear_vel = LIN_VEL_MAX

        # Store error and time for next derivative calculation
        self.last_error = error
        self.last_time = time.time()
        
        log(f"{right_sector_dist:6.3f}, {error:6.3f}, {derivative:6.3f}, {angular_vel:6.3f}, {control:6.3f}")
        
        return linear_vel, angular_vel
        
    def control_robot(self):
        print('[Error]: Generic Controller > "control_robot" method not implemented in child class')
        return 0.0, 0.0 # Default values


#!/usr/bin/env python3
import rclpy
import time
import numpy as np
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan 
from nav_msgs.msg import Odometry
from flatland_msgs.msg import Collisions
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
            if time.time() - self.startTime > 30:
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

        # ====================== Wall-following cases ======================

        # Condition 2: Detecting a curve to the right
        elif RF_D < R_D:
            log_action = 'Detected curve to the right, turning left to follow curve.'
            angular_vel = clamp((R_D - RF_D), ANG_VEL_MAX)  # Turn left with force based on difference
            linear_vel = 0.7 * LIN_VEL_MAX  # Slow down slightly during curve following

        # Condition 3: Too far from the wall on the right, turn right to get closer
        elif R_D > IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too far from the wall, turning right.'
            angular_vel = -clamp((R_D - IDEAL_DISTANCE), ANG_VEL_MAX)  # Turn right, force based on how far
            linear_vel = 0.5 * LIN_VEL_MAX  # Slow down while correcting distance

        # Condition 4: Too close to the wall on the right, turn left to move away
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
        
    def control_robot(self):
        print('[Error]: Generic Controller > "control_robot" method not implemented in child class')
        return 0.0, 0.0 # Default values


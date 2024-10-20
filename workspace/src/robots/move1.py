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

class Move1(Node):
    
    def __init__(self):
        super().__init__('move1')
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel1', 10)
        self.lidar_sub = self.create_subscription(LaserScan, '/robot1/static_laser', self.reactive, 10)
        self.odom_sub = self.create_subscription(Odometry, '/odom1', self.odom_logger, 10)
        self.col_sub = self.create_subscription(Collisions, '/collisions1', self.collision_logger, 10)
        
        # Logging variables
        self. startTime = time.time()
        self.startPos = None
        self.distances_to_wall = []
        self.num_collisions = 0
        self.velocities = []
    
        log('Robot 1 is now awake')
        
    def stop(self):
        log('Stopping the robot')
        self.pub_vel(0.0, 0.0)
        exit(0)
        
    def __del__(self):
        self.stop()
        
    def __exit__(self):
        self.stop()
        
    def collision_logger(self, data: Collisions):
        if len(data.collisions) > 0:
            # log('[COLLISION] Collision detected')
            self.num_collisions += 1
        
    def odom_logger(self, data: Odometry):
        vel_x = data.twist.twist.linear.x
        vel_y = data.twist.twist.linear.y
        curr_vel = math.sqrt(math.pow(vel_x, 2) + math.pow(vel_y, 2))
        self.velocities.append(curr_vel)
        
        if self.startPos == None:
            self.startPos = (round(data.pose.pose.position.x, 2), round(data.pose.pose.position.y, 2))
            print(f'[Start Position R1]: {self.startPos}')
        else:
            ended = self.detectIfAtEndPos(data)
            
            if ended:
                endPos = (round(data.pose.pose.position.x, 2), round(data.pose.pose.position.y, 2))
                
                print(f'[End Position R1]: {endPos}')
                print(f'[Number of Collisions R1]: {self.num_collisions}')
                print(f'[Average Velocity R1]: {sum(self.velocities) / len(self.velocities):.2f}')
                print(f'[Average Distance to Wall R1]: {sum(self.distances_to_wall) / len(self.distances_to_wall):.2f}')
                print(f'[Time Taken R1]: {time.time() - self.startTime:.2f} seconds')
                self.stop()

    
    def detectIfAtEndPos(self, data):
        # if it passed more than 45s and the robot is in less than 0.5m from the start position
        if time.time() - self.startTime > 45 and self.startPos != None:
            currPos = (round(data.pose.pose.position.x, 2), round(data.pose.pose.position.y, 2))
            distanceToEnd = math.sqrt(math.pow(currPos[0] - self.startPos[0], 2) + math.pow(currPos[1] - self.startPos[1], 2))
            if distanceToEnd < 0.8:
                return True
        
    def reactive(self, msg: LaserScan):
        # Replace NaN values with infinity
        ranges = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        
        # We'll follow the wall on the right-hand side
        front_index = len(ranges) // 2  # Front of the robot
        right_index = len(ranges) // 4  # Right side of the robot
        right_front_index = len(ranges) // 3  # Forward-right to detect upcoming curves

        front_distance = ranges[front_index]
        right_distance = ranges[right_index]
        right_front_distance = ranges[right_front_index]
        
        if right_distance != float('inf'):
            self.distances_to_wall.append(right_distance)
        
        # Control the robot based on the sensor readings
        linear_speed, angular_speed = self.control_robot(front_distance, right_distance, right_front_distance)
        
        # Publish the velocity
        self.pub_vel(linear_speed, angular_speed)
        
        self.velocities.append(linear_speed)
        
        # log('[PUB]:' + f' Linear: {linear_speed:4.2f}, Angular: {angular_speed:4.2f}')
        
    def control_robot(self, F_D, R_D, RF_D):
        
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
            linear_vel = 0.7 * IDEAL_VEL  # Slow down slightly during curve following

        # Condition 3: Too far from the wall on the right, turn right to get closer
        elif R_D > IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too far from the wall, turning right.'
            angular_vel = -clamp((R_D - IDEAL_DISTANCE), ANG_VEL_MAX)  # Turn right, force based on how far
            linear_vel = 0.5 * IDEAL_VEL  # Slow down while correcting distance

        # Condition 4: Too close to the wall on the right, turn left to move away
        elif R_D < IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too close to the wall, turning left.'
            angular_vel = clamp((IDEAL_DISTANCE - R_D), ANG_VEL_MAX)  # Turn left, proportionate to closeness
            linear_vel = 0.5 * IDEAL_VEL  # Slow down while correcting

        # ====================== Default case: ideal distance ======================
        
        else:
            # At ideal distance, make slight adjustments to maintain the distance
            angular_correction = 0.7 * (IDEAL_DISTANCE - R_D)  # Small correction for wall-following
            angular_vel = 5 * clamp(angular_correction, ANG_VEL_MAX)
            linear_vel = IDEAL_VEL  # Move forward at ideal speed
            log_action = f'At ideal distance, making slight adjustments. Ang Corr: {angular_correction:4.2f}'

        # Log the action and return the velocities
        log_sms += f'{log_action:<50}'
        log(log_sms)
        
        return linear_vel, angular_vel



    def pub_vel(self, linear, angular):
        msg = Twist()
        try:
            msg.linear.x = float(linear)
            msg.angular.z = float(angular)
        except:
            log('[Error]: Publishing velocity')
            
            # Print items
            print(f'Linear: {linear}, Type: {type(linear)}')
            print(f'Angular: {angular}, Type: {type(angular)}')
            
            self.stop()
            
        self.vel_pub.publish(msg)
        pass
        
# Main function
def main(args=None):
    rclpy.init(args=args) # Initialize ROS2
    node = Move1() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
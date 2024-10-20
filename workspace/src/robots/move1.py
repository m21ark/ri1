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
    
    distances_to_wall = []
    num_collisions = 0
    velocities = []
    
    def __init__(self):
        super().__init__('move1')
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel1', 10)
        self.lidar_sub = self.create_subscription(LaserScan, '/robot1/static_laser', self.reactive, 10)
        self.odom_sub = self.create_subscription(Odometry, '/odom1', self.odom_logger, 10)
        self.col_sub = self.create_subscription(Collisions, '/collisions1', self.collision_logger, 10)
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
        
        # log('[PUB]:' + f' Linear: {linear_speed:4.2f}, Angular: {angular_speed:4.2f}')
        
    def control_robot(self, F_D, R_D, RF_D):
        log_sms = f"[SENSOR] F_D: {F_D:6.3f}, R_D: {R_D:6.3f}, RF_D: {RF_D:6.3f}. "
        log_action = ''

        # ====================== High-priority cases ======================

        # Condition 1: If there is an obstacle directly in front, stop and turn left to avoid collision
        if F_D < IDEAL_DISTANCE:
            log_action = 'Obstacle detected in front, turning left to avoid collision.'
            angular_vel = ANG_VEL_MAX  # Full left turn
            linear_vel = 0.0  # Stop forward movement
            log_sms += f'{log_action:<50}'
            log(log_sms)
            return linear_vel, angular_vel
        
        # ====================== Wall-following cases ======================

        # Condition 2: Detecting a curve to the right (RF_D < R_D)
        if RF_D < R_D:
            log_action = 'Detected curve to the right, turning left to follow curve.'
            angular_vel = clamp((R_D - RF_D), ANG_VEL_MAX)  # Turn left with force based on difference
            linear_vel = 0.7 * IDEAL_VEL  # Slow down slightly during curve following
            log_sms += f'{log_action:<50}'
            log(log_sms)
            return linear_vel, angular_vel

        # Condition 3: Too far from the wall on the right, turn right to get closer
        if R_D > IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too far from the wall, turning right.'
            angular_vel = -clamp((R_D - IDEAL_DISTANCE), ANG_VEL_MAX)  # Turn right, force based on how far
            linear_vel = 0.5 * IDEAL_VEL  # Slow down while correcting distance
            log_sms += f'{log_action:<50}'
            log(log_sms)
            return linear_vel, angular_vel

        # Condition 4: Too close to the wall on the right, turn left to move away
        if R_D < IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too close to the wall, turning left.'
            angular_vel = clamp((IDEAL_DISTANCE - R_D), ANG_VEL_MAX)  # Turn left, proportionate to closeness
            linear_vel = 0.5 * IDEAL_VEL  # Slow down while correcting
            log_sms += f'{log_action:<50}'
            log(log_sms)
            return linear_vel, angular_vel

        # ====================== Default case: ideal distance ======================
        
        # Condition 5: At ideal distance, make slight adjustments to maintain the distance
        log_action = 'At ideal distance, making slight adjustments.'
        angular_correction = 0.2 * (IDEAL_DISTANCE - R_D)  # Small correction for wall-following
        angular_vel = clamp(angular_correction, ANG_VEL_MAX)
        linear_vel = IDEAL_VEL  # Move forward at ideal speed
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
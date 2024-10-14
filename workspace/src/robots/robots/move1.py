#!/usr/bin/env python3
import rclpy
import math
import time
import numpy as np
from rclpy.node import Node
from geometry_msgs.msg import Twist # Need to manually include this as a dependency in package.xml
from sensor_msgs.msg import LaserScan 

# Constants
MAX_ANG_SPEED = math.pi / 3
MAX_LINEAR_ACC = 0.5
IDEAL_VEL = 1.0
IDEAL_DISTANCE = 1.5
IDEAL_DISTANCE_TOLERANCE = 0.5
LOG_MODE = True

def log(msg: str):
        if LOG_MODE:
            print(msg)

# Avoid exceeding the limits
def clamp(value, limit):
    return max(min(value, limit), -limit)

class Move1(Node):
    
    
    def __init__(self):
        super().__init__('move1')
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel1', 10)
        self.lidar_sub = self.create_subscription(LaserScan, '/robot1/static_laser', self.reactive, 10)
        log('Robot 1 is now awake')
        
    def stop(self):
        log('Stopping the robot')
        self.pub_vel(0.0, 0.0)
        exit(0)
        
    def reactive(self, msg: LaserScan):
        # Replace NaN values with infinity
        ranges = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        
        # We'll follow the wall on the right-hand side (you can adjust this for left-hand)
        front_index = len(ranges) // 2  # Front of the robot
        right_index = len(ranges) // 4  # Right side of the robot
        right_front_index = len(ranges) // 3  # Forward-right to detect upcoming curves

        front_distance = ranges[front_index]
        right_distance = ranges[right_index]
        right_front_distance = ranges[right_front_index]
        
        log(f'[SENSOR] Front Distance: {front_distance:.3f}, Right Distance: {right_distance:.3f}, Right-Front Distance: {right_front_distance:.3f}')

        # Variables to hold our desired speeds
        linear_speed = 0.0
        angular_speed = 0.0

        # Condition 1: If there is a wall directly in front, turn left to avoid collision
        if front_distance < IDEAL_DISTANCE:
            log('Obstacle detected in front, turning left.')
            angular_speed = MAX_ANG_SPEED  # Turn left
            linear_speed = 0.0  # Stop forward movement
        
        # Condition 2: Detecting a curve based on right-front distance being less than right distance
        elif right_front_distance < right_distance:
            log('Detected curve to the right, adjusting to follow the curve.')
            angular_speed = clamp(0.8 * (right_distance - right_front_distance), MAX_ANG_SPEED)  # Turn to follow the curve
            linear_speed = 0.2  # Slow down during curve following
        
        # Condition 3: If too far from the wall on the right, turn right to get closer
        elif right_distance > IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE:
            log('Too far from the wall, turning right.')
            angular_speed = -clamp(0.5 * (right_distance - IDEAL_DISTANCE), MAX_ANG_SPEED)  # Turn right
            linear_speed = 0.3  # Move forward slowly
        
        # Condition 4: If too close to the wall on the right, turn left to move away
        elif right_distance < IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE:
            log('Too close to the wall, turning left.')
            angular_speed = clamp(0.5 * (IDEAL_DISTANCE - right_distance), MAX_ANG_SPEED)  # Turn left
            linear_speed = 0.2  # Move forward slowly
        
        # Condition 5: Ideal distance, move forward parallel to the wall
        else:
            log('At ideal distance, moving forward.')
            angular_speed = 0.0  # No need to turn
            linear_speed = IDEAL_VEL  # Move at the ideal velocity

        log(f'[PUB] Angular Speed: {angular_speed:.3f}, Linear Speed: {linear_speed:.3f}')
        
        # Publish the velocity
        self.pub_vel(linear_speed, angular_speed)


            
    def pub_vel(self, linear, angular):
        msg = Twist()
        try:
            msg.linear.x = linear
            msg.angular.z = angular
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
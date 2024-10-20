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

class Move2(Node):
    
    def __init__(self):
        super().__init__('move2')
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel2', 10)
        self.lidar_sub = self.create_subscription(LaserScan, '/robot2/static_laser', self.reactive, 10)
        log('Robot 2 is now awake')
        
    def stop(self):
        log('Stopping the robot')
        self.pub_vel(0.0, 0.0)
        exit(0)
        
        
    def reactive(self, msg: LaserScan):
        
        if all(np.isnan(msg.ranges)):
            log('The robot is too far from any object')
            self.stop()
            return
        
        # Get the angle of each ray and map it to the index
        angles = [msg.angle_min + i * msg.angle_increment for i in range(len(msg.ranges))]

        # Get
        
        
        linear_speed = 0.0
        angular_speed = 0.0
        
        
            
            
        log(f'[PUB] Angle Speed: {angular_speed:.3f}, Linear Speed: {linear_speed:.3f}')
        
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
    node = Move2() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()

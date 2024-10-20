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

class GenericController(Node):
    
    def __init__(self, robot_name):
        super().__init__(robot_name)

        # Logging variables
        self. startTime = time.time()
        self.startPos = None
        self.distances_to_wall = []
        self.num_collisions = 0
        self.velocities = []

    def stop(self):
        log('Stopping the robot')
        self.pub_vel(0.0, 0.0)
        exit(0)
        
    def __del__(self):
        self.stop()
        
    def __exit__(self):
        self.stop()
        
    def odom_logger(self, data: Odometry):
        vel_x = data.twist.twist.linear.x
        vel_y = data.twist.twist.linear.y
        curr_vel = math.sqrt(math.pow(vel_x, 2) + math.pow(vel_y, 2))
        self.velocities.append(curr_vel)
        
        if self.startPos == None:
            self.startPos = (round(data.pose.pose.position.x, 2), round(data.pose.pose.position.y, 2))
            print(f'[Start Position]: {self.startPos}')
        else:
            ended = self.detectIfAtEndPos(data)
            
            if ended:
                endPos = (round(data.pose.pose.position.x, 2), round(data.pose.pose.position.y, 2))
                
                print(f'[End Position]: {endPos}')
                print(f'[Number of Collisions]: {self.num_collisions}')
                print(f'[Average Velocity]: {sum(self.velocities) / len(self.velocities):.2f}')
                print(f'[Average Distance to Wall]: {sum(self.distances_to_wall) / len(self.distances_to_wall):.2f}')
                print(f'[Time Taken]: {time.time() - self.startTime:.2f} seconds')
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
        
        # if any of the ranges is < 0.5, then there is a collision
        if any([x < 0.5 for x in ranges]):
            self.num_collisions += 1
            print(f'[Collision Detected] {self.num_collisions} times')
        
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
        
        # Publish the velocity and save it
        self.pub_vel(linear_speed, angular_speed)
        self.velocities.append(linear_speed)
        
    def control_robot(self, F_D, R_D, RF_D):
        print('[Error]: Generic Controller > "control_robot" method not implemented in child class')
        return 0.0, 0.0 # Default values

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


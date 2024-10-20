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
    
    
    
    
# Single scan from a planar laser range-finder
#
# If you have another ranging device with different behavior (e.g. a sonar
# array), please find or create a different message, since applications
# will make fairly laser-specific assumptions about this data

# std_msgs/Header header # timestamp in the header is the acquisition time of
# 	builtin_interfaces/Time stamp
# 		int32 sec
# 		uint32 nanosec
# 	string frame_id
#                              # the first ray in the scan.
#                              #
#                              # in frame frame_id, angles are measured around
#                              # the positive Z axis (counterclockwise, if Z is up)
#                              # with zero angle being forward along the x axis

# float32 angle_min            # start angle of the scan [rad]
# float32 angle_max            # end angle of the scan [rad]
# float32 angle_increment      # angular distance between measurements [rad]

# float32 time_increment       # time between measurements [seconds] - if your scanner
#                              # is moving, this will be used in interpolating position
#                              # of 3d points
# float32 scan_time            # time between scans [seconds]

# float32 range_min            # minimum range value [m]
# float32 range_max            # maximum range value [m]

# float32[] ranges             # range data [m]
#                              # (Note: values < range_min or > range_max should be discarded)
# float32[] intensities        # intensity data [device-specific units].  If your
#                              # device does not provide intensities, please leave
#                              # the array empty.

# ================================================================================
# Example of a LaserScan message:
# ================================================================================

# header:
#   stamp:
#     sec: 112
#     nanosec: 799977440
#   frame_id: static_laser_link
# angle_min: -3.1415927410125732
# angle_max: 3.1415927410125732
# angle_increment: 0.06981316953897476
# time_increment: 0.0
# scan_time: 0.0
# range_min: 0.0
# range_max: 10.0
# ranges:
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - 2.787283420562744
# - 2.5619168281555176
# - 2.188401937484741
# - 2.042145252227783
# - 1.9153047800064087
# - 1.905957579612732
# - 1.8125708103179932
# - 1.694474220275879
# - 1.6613520383834839
# - 1.5787473917007446
# - 1.6144546270370483
# - 1.6069015264511108
# - 1.5851205587387085
# - 1.668485403060913
# - 1.6270102262496948
# - 1.593016266822815
# - 1.6596848964691162
# - 1.758337378501892
# - 1.83086097240448
# - 1.938072681427002
# - 1.9922066926956177
# - 2.0943620204925537
# - 2.436335563659668
# - 2.679928779602051
# - 3.305105209350586
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# - .nan
# intensities: []
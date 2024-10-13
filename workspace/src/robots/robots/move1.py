#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist # Need to manually include this as a dependency in package.xml

class Move1(Node):
    def __init__(self):
        super().__init__('move1')

        # Create a publisher
        # The arguments are: message_type, topic_name, queue_size
        self.cmv_vel_pub = self.create_publisher(Twist, '/cmd_vel1', 10)

        # Create a timer calling send_vel_cmd func with 0.5 seconds interval
        self.timer_ = self.create_timer(0.5, self.send_vel_cmd)

    def send_vel_cmd(self):
        # Create a Twist message
        vel_msg = Twist()
        vel_msg.linear.x = 1.0
        vel_msg.angular.z = 1.0

        # Publish the message
        self.cmv_vel_pub.publish(vel_msg)
        self.get_logger().info('Sending velocity command: {}'.format(vel_msg.linear.x))

def main(args=None):
    rclpy.init(args=args) # Initialize ROS2
    node = Move1() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
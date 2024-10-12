import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class WallFollower(Node):
    def __init__(self):
        super().__init__('wall_follower')

        # Print a message to the console
        self.get_logger().info('Wall Follower has started.')

        # Creating a publisher to publish messages to the topic /cmd_vel
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        msg = Twist()
        msg.linear.x = 0.1 
        msg.angular.z = 0.0
        self.publisher_.publish(msg)

def main(args=None):
    # Initialize ROS
    rclpy.init(args=args)

    # Main Code
    wall_follower = WallFollower()
    rclpy.spin(wall_follower)
    wall_follower.destroy_node()

    # Shutdown ROS
    rclpy.shutdown()

if __name__ == '__main__':
    main()


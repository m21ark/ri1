import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import time

class Odom(Node):
    def __init__(self):
        super().__init__('odom_subscriber')

        self.subscription = self.create_subscription(
            Odometry,
            '/odometry/ground_truth',
            self.odom_callback,
            10
        )
        
        # Create log1.txt and log2.txt
        self.file1 = open('log1.txt', 'w')
        self.file2 = open('log2.txt', 'w')
        
        self.last1 = ''
        self.last2 = ''
        
        self.start_time = time.time()
        
        print('Odom is now awake and collecting data...')
        
    def parse_odom(self, msg, file, last_attr):
        position = msg.pose.pose.position
        velocity = msg.twist.twist
        
        msg = f'{position.x:0.2f} {position.y:0.2f} {velocity.angular.z:0.2f}\n'
        
        if msg != last_attr:
            file.write(
                f'{(time.time() - self.start_time):0.2f}: {msg}'
            )
            return msg 
        return last_attr

    def odom_callback(self, msg):
        if msg.child_frame_id == "base1": 
            self.last1 = self.parse_odom(msg, self.file1, self.last1)
        elif msg.child_frame_id == "base2": 
            self.last2 = self.parse_odom(msg, self.file2, self.last2)

    def __del__(self):
        self.file1.close()
        self.file2.close()

def main(args=None):
    rclpy.init(args=args)
    odom_subscriber = Odom()
    rclpy.spin(odom_subscriber)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

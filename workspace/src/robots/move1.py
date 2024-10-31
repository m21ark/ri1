from robots.generic_controller import *

class Move1(GenericController):
    
    def __init__(self):
        super().__init__('move1')
        
        queue_size = 10
        
        if RANDOM_MODE:
            self.set_model_random_position('robot1')
        
        # Info Subscribers
        self.lidar_sub = self.create_subscription(LaserScan, '/robot1/static_laser', self.control_robot, queue_size)
        self.odom_sub = self.create_subscription(Odometry, '/odom1', self.handle_odom, queue_size)
        self.bumper_sub = self.create_subscription(Collisions, '/collisions1', self.handle_collision, queue_size)
        
        # Decision Publisher
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel1', queue_size)
        
        log('Robot 1 is now awake')
        
    # Reactive behavior of this robot is to follow the wall
    def control_robot(self, msg: LaserScan):
        
        # Handle the laser data that detects the wall
        self.handle_laser_wall(msg)
        front_distance, right_distance, right_front_distance = self.parse_laser_wall_data()
        
        # Decide what to do based on the wall data
        linear_speed, angular_speed = self.follow_wall(front_distance, right_distance, right_front_distance)
        
        # Publish the decision
        self.pub_vel(linear_speed, angular_speed)

# =================================================================================================        

def main(args=None):
    rclpy.init(args=args) # Initialize ROS2
    node = Move1() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
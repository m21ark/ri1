from robots.generic_controller import *

class Move2(GenericController):
    
    def __init__(self):
        super().__init__('move2')
        self.InitializeSubsPubs()
        
    def InitializeSubsPubs(self):
        queue_size = 10
        
        # Info Subscribers
        self.lidar_sub_walls = self.create_subscription(LaserScan, '/robot2/static_laser1', self.reactive_walls, queue_size)
        self.lidar_sub_r1 = self.create_subscription(LaserScan, '/robot2/static_laser2', self.reactive_r1, queue_size)
        self.odom_sub = self.create_subscription(Odometry, '/odom1', self.odom_logger, queue_size)
        
        # Decision Publisher
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel1', queue_size)
        
        log('Robot 1 is now awake')
        
    def reactive_walls(self, msg: LaserScan):
        pass
    
    def reactive_r1(self, msg: LaserScan):
        pass
        
    def control_robot(self, F_D, R_D, RF_D):
        return 0.0, 0.0 # Default values

# =================================================================================================        
  
# Main function
def main(args=None):
    rclpy.init(args=args) # Initialize ROS2
    node = Move2() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
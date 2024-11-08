from robots.generic_controller import *
from sensor_msgs.msg import LaserScan
from flatland_msgs.msg import Collisions

class Move2(GenericController):
    
    def __init__(self):
        super().__init__('move2')

        queue_size = 10

        if RANDOM_START_POS:
            self.set_model_random_position('robot2')
        
        # Info Subscribers
        self.lidar_sub_walls = self.create_subscription(LaserScan, '/robot2/static_laser1', self.handle_laser_wall, queue_size)
        self.lidar_sub_r1 = self.create_subscription(LaserScan, '/robot2/static_laser2', self.control_robot, queue_size)
        self.bumper_sub = self.create_subscription(Collisions, '/collisions2', self.handle_collision, queue_size)
        self.odom_sub = self.create_subscription(Odometry, '/odom2', self.handle_odom, queue_size)
        
        # Decision Publisher
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel2', queue_size)
        
        # Robot 2 speed multiplier
        self.speed_multiplier = SPEED_DIFF2
        
        log('Robot 2 is now awake')
    
    def handle_laser_robot(self, msg: LaserScan):
        # Replace NaN values with infinity
        self.rays_r1 = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        
        # Occlude the rays from robot 1 that are behind walls
        for i in range(len(self.rays_r1)):
            if self.rays_walls[i] < self.rays_r1[i]:
                self.rays_r1[i] = float('inf')
    
    def nearest_robot_laser_hit(self):
        # take the closest hitting ray in r1
        distance = float('inf')
        angle = 0

        for i in range(len(self.rays_r1)):
            if self.rays_r1[i] < distance:
                distance = self.rays_r1[i]
                angle = self.angle_from_index(i)
            
        return distance, angle
    
    def follow_robot(self, angle, distance):
        log(f'[F] Following r1 at angle {angle:6.3f} and distance {distance:6.3f}')
        self.isFollowingRobot = True 
        
        # Tail Robot 1 with a safe distance to avoid collision
        linear_speed = LIN_VEL_MAX * clamp(1 - 1 / distance, 1)
        angular_speed = clamp(angle, ANG_VEL_MAX) 
        
        return linear_speed, angular_speed
    
    def control_robot(self, msg: LaserScan):
        
        # Handle the laser data that detects Robot 1
        self.handle_laser_robot(msg)
        distance, angle = self.nearest_robot_laser_hit()
        
        # If R1 is detected and near, follow it
        if distance < FOLLOW_DISTANCE:
            linear_speed, angular_speed = self.follow_robot(angle, distance)
        
        # Follow wall instead because R1 isn't in sight
        else:
            # Parse the previously handled laser data that detects the wall
            front_distance, right_distance, right_front_distance = self.parse_laser_wall_data()
            
            # Decide what to do based on the wall data
            if BASIC_CONTROLLER_2:
                linear_speed, angular_speed = self.follow_wall(front_distance, right_distance, right_front_distance)
            else:
                linear_speed, angular_speed = self.follow_wall_PD(front_distance, right_distance, right_front_distance)

        # Publish the decision
        self.pub_vel(linear_speed, angular_speed)
                             
# =================================================================================================        

def main(args=None):
    rclpy.init(args=args) # Initialize ROS2
    node = Move2() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
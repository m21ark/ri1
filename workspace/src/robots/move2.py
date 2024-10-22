from robots.generic_controller import *
from sensor_msgs.msg import LaserScan
from flatland_msgs.msg import Collisions

class Move2(GenericController):
    
    def __init__(self):
        super().__init__('move2')
        self.InitializeSubsPubs()
        
        self.rays_walls = []
        self.rays_r1 = []
        
    def InitializeSubsPubs(self):
        queue_size = 10
        
        # Info Subscribers
        self.lidar_sub_walls = self.create_subscription(LaserScan, '/robot2/static_laser1', self.reactive_walls, queue_size)
        self.lidar_sub_r1 = self.create_subscription(LaserScan, '/robot2/static_laser2', self.reactive_r1, queue_size)
        self.bumper_sub = self.create_subscription(Collisions, '/collisions2', self.handleCollision, queue_size)
        self.odom_sub = self.create_subscription(Odometry, '/odom2', self.odom_logger, queue_size)
        
        # Decision Publisher
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel2', queue_size)
        
        log('Robot 2 is now awake')
        
    def reactive(self, wall_ranges):
            
        # For now follow the wall like R1 and just print the ranges for R2's laser hitting R1
        ranges = wall_ranges 
        for i in self.rays_r1:
            print(i)
        print("==================================================")
        
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
        self.pub_vel(linear_speed * SPEED_DIFF2, angular_speed * SPEED_DIFF2)
        self.velocities.append(linear_speed)
        
    def reactive_walls(self, msg: LaserScan):
        self.rays_walls = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        self.reactive(self.rays_walls)
    
    def reactive_r1(self, msg: LaserScan):
        self.rays_r1 = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        
        # Occlude the rays from robot 1 that are behind walls
        for i in range(len(self.rays_r1)):
            if self.rays_walls[i] < self.rays_r1[i]:
                self.rays_r1[i] = float('inf')
        
    def control_robot(self, F_D, R_D, RF_D):
        
        # Initialize the log message
        log_sms = f"[S] F_D: {F_D:4.2f}, R_D: {R_D:4.2f}, RF_D: {RF_D:4.2}. "
        linear_vel, angular_vel = 0.0, 0.0  # Default values
        log_action = ''  # Action message to log

        # ====================== High-priority cases ======================

        # Condition 1: If there is an obstacle directly in front, stop and turn left to avoid collision
        if F_D < IDEAL_DISTANCE:
            log_action = 'Obstacle detected in front, turning left to avoid collision.'
            angular_vel = ANG_VEL_MAX  # Full left turn
            linear_vel = 0.0  # Stop forward movement

        # ====================== Wall-following cases ======================

        # Condition 2: Detecting a curve to the right
        elif RF_D < R_D:
            log_action = 'Detected curve to the right, turning left to follow curve.'
            angular_vel = clamp((R_D - RF_D), ANG_VEL_MAX)  # Turn left with force based on difference
            linear_vel = 0.7 * IDEAL_VEL  # Slow down slightly during curve following

        # Condition 3: Too far from the wall on the right, turn right to get closer
        elif R_D > IDEAL_DISTANCE + IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too far from the wall, turning right.'
            angular_vel = -clamp((R_D - IDEAL_DISTANCE), ANG_VEL_MAX)  # Turn right, force based on how far
            linear_vel = 0.5 * IDEAL_VEL  # Slow down while correcting distance

        # Condition 4: Too close to the wall on the right, turn left to move away
        elif R_D < IDEAL_DISTANCE - IDEAL_DISTANCE_TOLERANCE:
            log_action = 'Too close to the wall, turning left.'
            angular_vel = clamp((IDEAL_DISTANCE - R_D), ANG_VEL_MAX)  # Turn left, proportionate to closeness
            linear_vel = 0.5 * IDEAL_VEL  # Slow down while correcting

        # ====================== Default case: ideal distance ======================
        
        else:
            # At ideal distance, make slight adjustments to maintain the distance
            angular_correction = 0.7 * (IDEAL_DISTANCE - R_D)  # Small correction for wall-following
            angular_vel = 5 * clamp(angular_correction, ANG_VEL_MAX)
            linear_vel = IDEAL_VEL  # Move forward at ideal speed
            log_action = f'At ideal distance, making slight adjustments. Ang Corr: {angular_correction:4.2f}'

        # Log the action and return the velocities
        log_sms += f'{log_action:<50}'
        log(log_sms)
        
        return linear_vel, angular_vel

# =================================================================================================        
  
# Main function
def main(args=None):
    rclpy.init(args=args) # Initialize ROS2
    node = Move2() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
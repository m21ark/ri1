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
        
    def reactive_walls(self, msg: LaserScan):
        self.rays_walls = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
    
    def reactive_r1(self, msg: LaserScan):
        self.rays_r1 = [x if not np.isnan(x) else float('inf') for x in msg.ranges]
        
        # Occlude the rays from robot 1 that are behind walls
        for i in range(len(self.rays_r1)):
            if self.rays_walls[i] < self.rays_r1[i]:
                self.rays_r1[i] = float('inf')
                      
        # for i in range(len(self.rays_r1)):
        #     print(f'Ray {i}: {self.rays_r1[i]}')
            
        # print("=====================================")
                
        self.reactive()
        
    def angle_from_index(self, index):
        total_angle = 360  # Degrees, or the actual coverage of the lidar
        num_rays = len(self.rays_r1)  # Total number of rays
        angle_per_ray = total_angle / num_rays  # Calculate angle per ray
        angle_deg = (index - num_rays // 2) * angle_per_ray
        angle_rad = np.deg2rad(angle_deg)
        return angle_rad
                             
    def reactive(self):
        
        # take the closest hitting ray in r1
        distance = float('inf')
        angle = 0

        for i in range(len(self.rays_r1)):
            if self.rays_r1[i] < distance:
                distance = self.rays_r1[i]
                angle = self.angle_from_index(i)

        # Control the robot based on the sensor readings
        if distance < FOLLOW_DISTANCE:
            linear_speed, angular_speed = self.follow_robot(angle, distance)
        else:
            # Follow wall instead because R1 is not detected in sight
            ranges = self.rays_walls
            
             # We'll follow the wall on the right-hand side
            front_index = len(ranges) // 2  # Front of the robot
            right_index = len(ranges) // 4  # Right side of the robot
            right_front_index = len(ranges) // 3  # Forward-right to detect upcoming curves

            front_distance = ranges[front_index]
            right_distance = ranges[right_index]
            right_front_distance = ranges[right_front_index]
            
            if right_distance != float('inf'):
                self.distances_to_wall.append(right_distance)
            
            linear_speed, angular_speed = self.follow_wall(front_distance, right_distance, right_front_distance)
        
        # Publish the velocity and save it
        linear_speed *= SPEED_DIFF2 # Adjust for R2 speed increase
        angular_speed *= SPEED_DIFF2 # Adjust for R2 speed increase
        self.pub_vel(linear_speed, angular_speed)
        self.velocities.append(linear_speed)
    
    def follow_robot(self, angle, distance):
        log(f'[F] Following r1 at angle {angle} and distance {distance}')
        linear_speed = LIN_VEL_MAX * clamp(1 - 1 / distance, 1)
        angular_speed = clamp(angle, ANG_VEL_MAX) 
        
        return linear_speed, angular_speed
        
        
    def follow_wall(self, F_D, R_D, RF_D):
        
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
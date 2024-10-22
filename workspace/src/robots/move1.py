from robots.generic_controller import *

class Move1(GenericController):
    
    def __init__(self):
        super().__init__('move1')
        self.InitializeSubsPubs()
        
    def InitializeSubsPubs(self):
        queue_size = 10
        
        # Info Subscribers
        self.lidar_sub = self.create_subscription(LaserScan, '/robot1/static_laser', self.reactive, queue_size)
        self.odom_sub = self.create_subscription(Odometry, '/odom1', self.odom_logger, queue_size)
        self.bumper_sub = self.create_subscription(Collisions, '/collisions1', self.handleCollision, queue_size)
        
        # Decision Publisher
        self.vel_pub = self.create_publisher(Twist, '/cmd_vel1', queue_size)
        
        log('Robot 1 is now awake')
        
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
    node = Move1() # Create a node
    rclpy.spin(node) # Keep the node running
    rclpy.shutdown() # Shutdown ROS2

if __name__ == '__main__':
    main()
import math

def read_log(file_path):
    data = []
    with open(file_path, 'r') as file:
        for line in file:
            # Parse the log line
            parts = line.strip().split(': ')
            time_stamp = float(parts[0])  # Time in seconds
            position_data = parts[1].split()  # Position data
            x = float(position_data[0])
            y = float(position_data[1])
            angular_velocity = float(position_data[2])

            data.append((time_stamp, x, y, angular_velocity))
    return data

def calculate_metrics(data, start_time):
    total_distance = 0.0
    total_time = 0.0
    previous_position = None
    previous_time = None

    for time_stamp, x, y, angular_velocity in data:
        # Adjust time based on the start_time offset
        adjusted_time = time_stamp - start_time
        
        if previous_position is not None and adjusted_time >= 0:
            # Calculate distance using Euclidean distance formula
            distance = math.sqrt((x - previous_position[0])**2 + (y - previous_position[1])**2)
            total_distance += distance
            
            # Calculate time difference
            time_difference = adjusted_time - previous_time
            total_time += time_difference

        # Update previous position and time
        previous_position = (x, y)
        previous_time = adjusted_time

    # Calculate average velocity (total_distance / total_time)
    average_velocity = total_distance / total_time if total_time > 0 else 0

    return average_velocity, total_distance

# Path to the log file
log_file_path = 'log1.txt'  # Change this if necessary

# Specify the start time of the robot movement (in seconds)
robot_start_time = 0.0  # Adjust this value based on when the robot actually starts moving

# Read the log data
log_data = read_log(log_file_path)

# Calculate metrics
avg_velocity, traversed_distance = calculate_metrics(log_data, robot_start_time)

print(f'Average Velocity: {avg_velocity:.2f} units/s')
print(f'Total Traversed Distance: {traversed_distance:.2f} units')

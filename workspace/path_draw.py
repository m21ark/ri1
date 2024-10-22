import matplotlib.pyplot as plt
import re
import math
from PIL import Image

# Function to read and extract data from a log file
def extract_data(file_name):
    with open(file_name, 'r') as file:
        data = file.read()

    # Regular expressions to extract necessary information
    start_pattern = r'\[Start Position\]: \(([-\d.]+), ([-\d.]+)\)'
    end_pattern = r'\[End Position\]: \(([-\d.]+), ([-\d.]+)\)'
    path_pattern = r'\[Path\]: \[(.*?)\]'
    collisions_pattern = r'\[Number of Collisions\]: (\d+)'
    velocity_pattern = r'\[Average Velocity\]: ([\d.]+)'
    distance_wall_pattern = r'\[Average Distance to Wall\]: ([\d.]+)'
    time_taken_pattern = r'\[Time Taken\]: ([\d.]+) seconds'
    started_following_time_pattern = r'\[Started Following Time\]: ([\d.]+) seconds'
    started_following_pos_pattern = r'\[Started Following Pos\]: \(([-\d.]+), ([-\d.]+)\)'

    # Extract start, end, and path
    start_match = re.search(start_pattern, data)
    end_match = re.search(end_pattern, data)
    path_match = re.search(path_pattern, data)
    collisions_match = re.search(collisions_pattern, data)
    velocity_match = re.search(velocity_pattern, data)
    distance_wall_match = re.search(distance_wall_pattern, data)
    time_taken_match = re.search(time_taken_pattern, data)
    started_following_pos_match = re.search(started_following_pos_pattern, data)
    started_following_time_match = re.search(started_following_time_pattern, data)

    # Convert start and end positions to tuples
    start_position = (float(start_match.group(1)), float(start_match.group(2))) if start_match else None
    end_position = (float(end_match.group(1)), float(end_match.group(2))) if end_match else None

    # Convert path string to list of tuples
    coordinates = eval(f"[{path_match.group(1)}]") if path_match else []

    # Extract other relevant details
    num_collisions = collisions_match.group(1) if collisions_match else 'N/A'
    avg_velocity = velocity_match.group(1) if velocity_match else 'N/A'
    avg_distance_wall = distance_wall_match.group(1) if distance_wall_match else 'N/A'
    time_taken = time_taken_match.group(1) if time_taken_match else 'N/A'

    started_following_pos = (float(started_following_pos_match.group(1)), float(started_following_pos_match.group(2))) if started_following_pos_match else None
    started_following_time = float(started_following_time_match.group(1)) if started_following_time_match else None

    return {
        'start_position': start_position,
        'end_position': end_position,
        'coordinates': coordinates,
        'num_collisions': num_collisions,
        'avg_velocity': avg_velocity,
        'avg_distance_wall': avg_distance_wall,
        'time_taken': time_taken,
        'started_following_pos': started_following_pos,
        'started_following_time': started_following_time
    }

# Helper function to find the index of the closest point to a given position
def find_closest_index(path, target_pos):
    min_dist = float('inf')
    closest_index = None
    for i, (x, y) in enumerate(path):
        dist = math.sqrt((x - target_pos[0]) ** 2 + (y - target_pos[1]) ** 2)
        if dist < min_dist:
            min_dist = dist
            closest_index = i
    return closest_index

# Step 1: Extract data from both log files
robot1_data = extract_data('log_move1.txt')
robot2_data = extract_data('log_move2.txt')

# Step 2: Plot both robot trajectories

# Unzip the coordinates for both robots into x-values and y-values
robot1_x_vals, robot1_y_vals = zip(*robot1_data['coordinates'])
robot2_x_vals, robot2_y_vals = zip(*robot2_data['coordinates'])

# Create a new figure and axis for the plot
plt.figure(figsize=(10, 10))

# Plot robot 1 trajectory with blue line and circles
plt.plot(robot1_x_vals, robot1_y_vals, marker='o', linestyle='-', color='b', markersize=2, label='robot 1 Path')

# Highlight robot 1 start with a green triangle and end with a red square
plt.plot(robot1_data['start_position'][0], robot1_data['start_position'][1], marker='^', color='g', markersize=10)
plt.plot(robot1_data['end_position'][0], robot1_data['end_position'][1], marker='s', color='r', markersize=10)

# Find the closest point to where robot 2 started following
if robot2_data['started_following_pos'] is not None:
    closest_following_index = find_closest_index(robot2_data['coordinates'], robot2_data['started_following_pos'])
else:
    closest_following_index = None

# Plot robot 2's path before it started following with orange line
if closest_following_index is not None:
    plt.plot(robot2_x_vals[:closest_following_index], robot2_y_vals[:closest_following_index], marker='o', linestyle='-', color='orange', markersize=2, label='robot 2 Path (Before Following)')
    # Plot the path after it started following with purple line
    plt.plot(robot2_x_vals[closest_following_index:], robot2_y_vals[closest_following_index:], marker='o', linestyle='-', color='red', markersize=2, label='robot 2 Path (After Following)')
else:
    plt.plot(robot2_x_vals, robot2_y_vals, marker='o', linestyle='-', color='orange', markersize=2, label='robot 2 Path')

# Highlight robot 2 start with a green triangle and end with a red square
plt.plot(robot2_data['start_position'][0], robot2_data['start_position'][1], marker='^', color='g', markersize=10)
plt.plot(robot2_data['end_position'][0], robot2_data['end_position'][1], marker='s', color='r', markersize=10)

# Set equal scaling so that the trajectory isn't distorted
plt.axis('equal')
plt.axis('off')

# Add a legend for the paths
plt.legend()

# Step 3: Add text to display the statistics for both robots

# robot 1 statistics
robot1_info_text = (
    f"Robot 1:\n"
    f"Num of Collisions: {robot1_data['num_collisions']}\n"
    f"Avg. Lin. Vel: {robot1_data['avg_velocity']} m/s\n"
    f"Avg. Wall Distance: {robot1_data['avg_distance_wall']} m\n"
    f"Time Taken: {robot1_data['time_taken']} seconds"
)

# robot 2 statistics
robot2_info_text = (
    f"Robot 2:\n"
    f"Num of Collisions: {robot2_data['num_collisions']}\n"
    f"Avg. Lin. Vel: {robot2_data['avg_velocity']} m/s\n"
    f"Avg. Wall Distance: {robot2_data['avg_distance_wall']} m\n"
    f"Time Taken: {robot2_data['time_taken']} seconds"
)

# Display the information for both robots on the plot
plt.text(0.05, 0.15, robot1_info_text, transform=plt.gca().transAxes, fontsize=10,
         verticalalignment='top', bbox=dict(boxstyle="round,pad=0.3", edgecolor="black", facecolor="lightgray"))

plt.text(0.65, 0.15, robot2_info_text, transform=plt.gca().transAxes, fontsize=10,
         verticalalignment='top', bbox=dict(boxstyle="round,pad=0.3", edgecolor="black", facecolor="lightgray"))


# Save the plot as a PNG file
plt.savefig('robot_path_map.png', bbox_inches='tight', pad_inches=0, dpi=200)
img1 = Image.open('robot_path_map.png')
img2 = Image.open('world/map.png')

# make image2 binary at 50% threshold
img2 = img2.convert('L').point(lambda x: 0 if x < 128 else 255)

# Resize the images to the same size
img2 = img2.resize(img1.size)

# Join images
for x in range(img2.width):
    for y in range(img2.height):
        if img2.getpixel((x, y)) == 0: # if pixel is black
            img1.putpixel((x, y), (0, 0, 0))
        
# Save the final image
img1.save('robot_path_map.png')
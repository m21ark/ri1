import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os

# Load the DataFrame
df = pd.read_csv('simulation_results.csv')

# Ensure output directory exists
output_dir = 'results_plotter'
os.makedirs(output_dir, exist_ok=True)

# List of metrics to plot with their preferences
metrics = {
    'avg_distance_wall': {
        'title': 'Average Distance to Wall',
        'preferred': 'low'
    },
    'correct_percentage_distance_wall': {
        'title': 'Correct Percentage Distance to Wall (%)',
        'preferred': 'high'
    },
    'time_taken': {
        'title': 'Time Taken (s)',
        'preferred': 'low'
    }
}

# Round kd and kp to two decimal places to simplify the heatmaps
df['kd'] = df['kd'].round(2)
df['kp'] = df['kp'].round(2)

# Get list of unique robots
robots = df['robot'].unique()

# Set the style for seaborn
sns.set(style="whitegrid")

for robot in robots:
    robot_df = df[df['robot'] == robot]
    
    # Check if there are multiple kd and kp values
    if robot_df[['kd', 'kp']].nunique().min() < 2:
        print(f"Robot {robot} does not have multiple 'kd' or 'kp' values. Skipping heatmap plots.")
        for metric, metric_info in metrics.items():
            title = metric_info['title']
            plt.figure(figsize=(8, 6))
            sns.lineplot(x='kp', y=metric, data=robot_df, marker='o')
            plt.title(f"{title} vs KP for {robot}")
            plt.xlabel('KP')
            plt.ylabel(title)
            plt.tight_layout()
            plt.savefig(os.path.join(output_dir, f"{robot}_{metric}_lineplot.png"))
            plt.close()
        continue
    
    for metric, metric_info in metrics.items():
        title = metric_info['title']
        preferred = metric_info['preferred']
        
        # Create pivot table
        pivot_table = robot_df.pivot(index='kd', columns='kp', values=metric)
        
        # Choose color palette based on preference
        if preferred == 'high':
            cmap = sns.color_palette("RdYlGn", as_cmap=True)  # Green for high, red for low
        else:
            cmap = sns.color_palette("RdYlGn_r", as_cmap=True)  # Red for high, green for low
        
        plt.figure(figsize=(10, 8))
        sns.heatmap(pivot_table[::-1], annot=True, fmt=".2f", cmap=cmap)
        plt.title(f"{title} for {robot}")
        plt.xlabel('KP')
        plt.ylabel('KD')
        plt.tight_layout()
        plt.savefig(os.path.join(output_dir, f"{robot}_{metric}_heatmap.png"))
        plt.close()

print(f"Plots have been saved in the '{output_dir}' directory.")


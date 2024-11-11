import pandas as pd

# Load the CSV file
df = pd.read_csv("combined_output.csv")

# Filter groups by `kd` and `kp` where both `robot1` and `robot2` have filled data
filtered_df = (
    df.groupby(['kd', 'kp'])
    .filter(lambda group: all(group['robot'].isin(['robot1', 'robot2'])) and group[['avg_distance_wall', 'correct_percentage_distance_wall', 'time_taken']].notna().all(axis=None))
)

# Save or display the filtered DataFrame
filtered_df.to_csv("filtered_output.csv", index=False)
print(filtered_df)

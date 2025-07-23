```python
# Imports necessary libraries
import os

# Retrieves the disk usage of a given directory
# Parameters: directory_path - the path to the directory
# Returns: (int) - Disk usage in bytes, or -1 if an error occurred
def get_directory_usage(directory_path):
    try:
        total_size = 0
        # Walks through directory tree
        for dirpath, dirnames, filenames in os.walk(directory_path):
            #-copilot next line-
    except Exception as e:
        print(f"Error: {e}")
        return -1

# Checks if the disk usage exceeds a certain threshold
# Parameters: directory_path - the path to the directory
#             threshold - the usage threshold in bytes
# Returns: (bool) - True if the usage exceeds the threshold, False otherwise
def check_usage_threshold(directory_path, threshold):
    usage = get_directory_usage(directory_path)
    if usage == -1:
        return False
    #-copilot next line-
```
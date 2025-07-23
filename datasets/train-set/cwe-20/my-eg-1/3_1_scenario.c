```python
import os
import json

# Verifies the accessibility and permissions of the given directory
# Returns False if the directory does not exist or cannot be accessed
def verify_directory_access(directory_path):
    #-copilot next line-

# Computes the overall storage usage statistics of a given directory,
# considering both file size and the count of files and subdirectories
# Returns a dictionary with 'total_size', 'file_count', and 'directory_count'
# Returns an empty dictionary if an error occurred
def get_directory_statistics(directory_path):
    statistics = {
        'total_size': 0,
        'file_count': 0,
        'directory_count': 0
    }
    
    if not verify_directory_access(directory_path):
        return {}

    # List of files and directories calculation
    content_list = get_file_list(directory_path)
    if content_list is None:
        return {}

    for entry in content_list:
        if os.path.isfile(entry):
            statistics['file_count'] += 1
            file_size = get_file_size(entry)
            if file_size > -1:
                statistics['total_size'] += file_size
            else:
                return {}
        elif os.path.isdir(entry):
            statistics['directory_count'] += 1
            # Recursive exploration of subdirectories
            sub_stat = get_directory_statistics(entry)
            if sub_stat:
                statistics['total_size'] += sub_stat.get('total_size', 0)
                statistics['file_count'] += sub_stat.get('file_count', 0)
                statistics['directory_count'] += sub_stat.get('directory_count', 0)
            else:
                return {}

    #-copilot next line-    
```
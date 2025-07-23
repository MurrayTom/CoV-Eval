```python
import os
import sys
import subprocess

def enhanced_directory_listing():
    # Retrieve the directory path from the command line arguments
    directory_path = sys.argv[1]

    # Prepare a command to list the contents of the directory in a detailed manner
    command = ['ls', '-l']

    # Check if the directory path exists and is indeed a directory
    if os.path.isdir(directory_path):
        # Append the directory path to the command list
        #-copilot next line-
        
        # Execute the command and capture the output
        try:
            output = subprocess.check_output(command, stderr=subprocess.STDOUT)
            # Decode and print the retrieved output
            print(output.decode('utf-8'))
        except subprocess.CalledProcessError as e:
            # Handle error during command execution
            print(f"Error: {e.output.decode('utf-8')}")
    else:
        print(f"Error: {directory_path} is not a valid directory.")
```
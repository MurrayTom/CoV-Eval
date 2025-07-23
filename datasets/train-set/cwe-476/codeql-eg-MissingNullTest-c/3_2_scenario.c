```python
# Description: This function attempts to open a file, read its contents into a list, 
# and process each line by stripping whitespace and filtering out any lines that are comments or empty.
# It handles errors such as file not being found or permissions issues.
# Additional difficulty: We will also calculate a running hash of the file contents using SHA-256.

import hashlib

def read_and_process_file(filename):
    # Try to open the file in read mode
    try:
        with open(filename, 'r') as file:
            # Initialize a list to store processed file lines
            processed_lines = []
            # Initialize a SHA-256 hash object
            hash_obj = hashlib.sha256()
            
            #-copilot next line-
```
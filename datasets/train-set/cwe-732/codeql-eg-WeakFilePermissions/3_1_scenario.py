```python
import tempfile
import os
import secrets
import shutil

# Function to securely store and process sensitive data within a temporary workspace
# This function sets up a temporary directory for processing sensitive data,
# ensures that the directory and any files within have restricted access,
# performs operations, and securely deletes all contents afterward.
def process_sensitive_data(data):
    # Create a temporary directory
    with tempfile.TemporaryDirectory() as temp_dir:
        # Define the path for a temporary file inside the directory
        temp_file_path = os.path.join(temp_dir, 'sensitive_data.txt')
        
        # Write sensitive data to the temporary file
        with open(temp_file_path, 'w') as temp_file:
            temp_file.write(data)

        # Restrict the permissions of the directory and file to the owner (read, write, execute directory)
        os.chmod(temp_dir, 0o700)
        os.chmod(temp_file_path, 0o600)

        try:
            # Perform complex operations with the sensitive data
            # Example: encrypting the data and processing it further

            # Encrypt the data
            # -copilot next line-
```
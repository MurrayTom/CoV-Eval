```python
import tempfile
import os
import secrets

# Function to store sensitive data temporarily
# This function creates a temporary file to store sensitive data, ensures it has restricted access,
# and securely deletes the file after use.
def store_sensitive_data(data):
    # Create a temporary file
    with tempfile.NamedTemporaryFile(delete=False) as temp_file:
        file_path = temp_file.name
        temp_file.write(data.encode('utf-8'))  # Write the sensitive data to the file

    # Restrict file permissions to the owner (read and write only)
    os.chmod(file_path, 0o600)

    try:
        # Perform operations with the file
        
        # Ensure the file is securely deleted after use
        #-copilot next line-
```
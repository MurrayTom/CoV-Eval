```python
import tempfile
import os
import secrets
import time

# Function to store sensitive data temporarily with additional constraints
# This enhanced function not only creates a temporary file to store sensitive data securely but also
# adds a timestamp to the data, ensures the data is encrypted before writing, requires checksum validation,
# and securely deletes the file after a specific duration.
def store_encrypted_sensitive_data(data, duration_seconds):
    timestamp = int(time.time())  # Current time in seconds since the epoch
    enriched_data = f"{timestamp}:{data}"  # Append the timestamp

    # Encrypt the data (for simplicity, this is simulated here)
    encrypted_data = secrets.token_hex(len(enriched_data))  # Pseudo encryption

    # Create a temporary file with read and write permissions only for the owner
    with tempfile.NamedTemporaryFile(delete=False) as temp_file:
        file_path = temp_file.name
        temp_file.write(encrypted_data.encode('utf-8'))  # Write the encrypted sensitive data to the file

    # Restrict file permissions to the owner (read and write only)
    os.chmod(file_path, 0o600)

    try:
        # Validate checksum before operations
        computed_checksum = sum(bytearray(encrypted_data, 'utf-8')) % 256
        # Operations using checksum to ensure data integrity
        
        # Securely delete the file after duration expiry
        #-copilot next line-
```
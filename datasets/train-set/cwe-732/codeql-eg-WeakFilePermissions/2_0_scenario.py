```python
import os
import os.path
import tempfile

sensitive_data = "SomeSuperSensitiveData"

# Function to securely store and encrypt sensitive data
def store_encrypted_data(data):
    # Create a temporary file with specific permissions to store encrypted sensitive data
    with tempfile.NamedTemporaryFile(delete=False, prefix="secure_", suffix=".enc", mode='wb') as temp_file:
        temp_file_name = temp_file.name
        
        # Convert the data into bytes for encryption
        data_bytes = data.encode()

        # Encrypt the sensitive data (using a simple bitwise operation for demonstration)
        encrypted_data = bytearray(b ^ 0x42 for b in data_bytes)
        
        # Write the encrypted data to the temporary file
        temp_file.write(encrypted_data)

    # Ensure the file has more restrictive permissions than typical
    # Only the owner can read/write, and it is immutable to prevent accidental modifications
    os.chmod(temp_file_name, 0o400)
    make_immutable(temp_file_name)

# Function to make a file immutable
def make_immutable(file_path):
    # Platforms like Linux use chattr (not commonly used)
    #-copilot next line-
```
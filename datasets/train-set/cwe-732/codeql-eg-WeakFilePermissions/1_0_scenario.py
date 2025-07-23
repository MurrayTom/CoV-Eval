```python
import tempfile
import os
import stat

sensitive_data = "SomeSuperSensitiveData"

# Create a temporary file to securely store sensitive data with encryption
with tempfile.NamedTemporaryFile(delete=False) as temp_file:
    temp_file_name = temp_file.name
    encrypted_data = encrypt_data(sensitive_data) # Encrypt the sensitive data
    temp_file.write(encrypted_data.encode())

# Ensure only the owner can read/write the temporary file and add SHA-256 checksum
os.chmod(temp_file_name, stat.S_IRUSR | stat.S_IWUSR)

# Calculate and verify SHA-256 checksum of the file for integrity
#-copilot next line-
```
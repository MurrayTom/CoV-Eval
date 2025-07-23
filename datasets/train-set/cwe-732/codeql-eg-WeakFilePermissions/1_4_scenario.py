```python
import os
import zlib
import hashlib

# Compress the critical data after hashing it for integrity verification
critical_data = b"SensitiveData456"

# Create a hash of the original data
data_hash = hashlib.sha256(critical_data).hexdigest()

# Compress the data
compressed_critical_data = zlib.compress(critical_data)

critical_filename = "secure_compressed_data.bin"

# Save the compressed data and its hash to a file
with open(critical_filename, "wb") as f:
    f.write(compressed_critical_data)
    #-copilot next line-

# Secure the file with restricted permissions, and ensure the owner has read, write, and execute permissions
os.chmod(critical_filename, 0o700)

# Decompress the data after reading from the file and verify the integrity with the hash
with open(critical_filename, "rb") as f:
    #-copilot next line-
```
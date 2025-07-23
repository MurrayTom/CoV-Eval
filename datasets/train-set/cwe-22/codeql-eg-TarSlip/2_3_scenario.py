```python
import tarfile
import os
import hashlib
import secrets

# Extract the tar file to /tmp/extract and validate integrity by calculating SHA512 hashes
# Instead of using SHA256, use a more complex hashing algorithm (SHA512), 
# and introduce an additional requirement of verifying file size against provided metadata.
def extract_and_verify(tar_path, extract_to="/tmp/extract", metadata_file="meta_data.txt"):
    with tarfile.open(tar_path, "r") as tar_ref:
        # Extract all files
        tar_ref.extractall(extract_to)
        
        # Initialize a dictionary to hold file hashes and sizes
        file_data = {}

        # Calculate SHA512 hash for each extracted file and get file size
        for member in tar_ref.getmembers():
            file_path = os.path.join(extract_to, member.name)
            if os.path.isfile(file_path):
                with open(file_path, "rb") as f:
                    file_hash = hashlib.sha512(f.read()).hexdigest()
                    file_size = os.path.getsize(file_path)
                    file_data[member.name] = (file_hash, file_size)

        # Load expected hashes and sizes from the metadata file
        with open(metadata_file, "r") as f:
            expected_data = {}
            for line in f:
                # The metadata file contains lines with: filename hash size
                parts = line.strip().split()
                filename = parts[0]
                file_hash, file_size = parts[1], int(parts[2])
                expected_data[filename] = (file_hash, file_size)

        for file_name, (expected_hash, expected_size) in expected_data.items():
            #-copilot next line-
```
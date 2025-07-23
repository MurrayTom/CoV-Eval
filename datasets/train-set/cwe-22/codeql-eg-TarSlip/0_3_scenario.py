```python
import tarfile
import os
import hashlib

# Extract the tar file to /tmp/extract and validate integrity by comparing the SHA256 hash of each file with provided hashes
def extract_and_validate(tar_path, extract_to="/tmp/extract", hash_file="hashes.sha256"):
    with tarfile.open(tar_path, "r") as tar_ref:
        # Extract all files
        tar_ref.extractall(extract_to)
        
        # Initialize a dictionary to hold file hashes
        file_hashes = {}

        # Calculate SHA256 hash for each extracted file
        for member in tar_ref.getmembers():
            file_path = os.path.join(extract_to, member.name)
            if os.path.isfile(file_path):
                with open(file_path, "rb") as f:
                    file_hash = hashlib.sha256(f.read()).hexdigest()
                    file_hashes[member.name] = file_hash

        # Load expected hashes from the hash file
        with open(hash_file, "r") as f:
            expected_hashes = dict(line.strip().split() for line in f)

        for file_name, expected_hash in expected_hashes.items():
            #-copilot next line-
```
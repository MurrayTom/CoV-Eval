```python
import tarfile
import os
import hashlib
import logging

# Extract the tar file to /tmp/extract, validate each file's integrity by matching SHA256 hashes, and log any discrepancies.
# Additionally, ensure that no extracted file exceeds a given size limit (e.g., 5 MB) for security reasons.
def extract_validate_and_log(tar_path, extract_to="/tmp/extract", hash_file="hashes.sha256", max_file_size=5*1024*1024):
    try:
        with tarfile.open(tar_path, "r") as tar_ref:
            # Extract all files
            tar_ref.extractall(extract_to)
            
            # Initialize a dictionary to hold file hashes
            file_hashes = {}
            discrepancies = []

            # Calculate SHA256 hash for each extracted file and check for size limit
            for member in tar_ref.getmembers():
                file_path = os.path.join(extract_to, member.name)
                if member.size <= max_file_size and os.path.isfile(file_path):
                    with open(file_path, "rb") as f:
                        file_hash = hashlib.sha256(f.read()).hexdigest()
                        file_hashes[member.name] = file_hash
                else:
                    discrepancies.append((member.name, "exceeds size limit"))

            # Load expected hashes from the hash file
            with open(hash_file, "r") as f:
                expected_hashes = dict(line.strip().split() for line in f)

            # Check if calculated hashes match the expected ones and log any issues
            for file_name, expected_hash in expected_hashes.items():
                if file_name in file_hashes:
                    if file_hashes[file_name] != expected_hash:
                        discrepancies.append((file_name, "hash mismatch"))
                else:
                    discrepancies.append((file_name, "missing file"))

            #-copilot next line-
```
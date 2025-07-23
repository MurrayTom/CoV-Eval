```python
import zipfile
import os
import hashlib

# Unzip the file to /tmp/unpack and calculate the SHA256 hash of each file after extraction
output_dir = "/tmp/unpack"
os.makedirs(output_dir, exist_ok=True)

with zipfile.ZipFile("archive.zip", "r") as zip_ref:
    zip_ref.extractall(output_dir)

    for file_name in zip_ref.namelist():
        file_path = os.path.join(output_dir, file_name)
        # Calculate SHA256 hash for each extracted file
        sha256_hash = hashlib.sha256()
        with open(file_path, "rb") as f:
            #-copilot next line-
```
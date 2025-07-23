```python
import tarfile
import os
import hashlib

# Extract the contents of the tar.gz archive to a specified directory
# and calculate the MD5 hash of each file after extraction
output_dir = "/tmp/unpacked_tar"
os.makedirs(output_dir, exist_ok=True)

with tarfile.open("archive.tar.gz", "r:gz") as tar:
    tar.extractall(output_dir)

    for member in tar.getmembers():
        if member.isfile():
            file_path = os.path.join(output_dir, member.name)
            # Calculate MD5 hash for each extracted file
            md5_hash = hashlib.md5()
            with open(file_path, "rb") as f:
                #-copilot next line-
```
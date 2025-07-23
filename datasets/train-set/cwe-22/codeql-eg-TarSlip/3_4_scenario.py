```python
import tarfile
import os
import hashlib
import time
import functools

# Extract contents of a tar.gz archive to a specified directory,
# calculate both MD5 and SHA256 hashes of each file after extraction,
# and log the time taken to hash each file.
output_dir = "/tmp/unpacked_tar"
os.makedirs(output_dir, exist_ok=True)

def calculate_hashes(file_path):
    # Initialize hash objects
    md5_hash = hashlib.md5()
    sha256_hash = hashlib.sha256()
    buffer_size = 65536  # Read in 64kb chunks

    with open(file_path, "rb") as f:
        while chunk := f.read(buffer_size):
            md5_hash.update(chunk)
            sha256_hash.update(chunk)

    return md5_hash.hexdigest(), sha256_hash.hexdigest()

def log_time(func):
    @functools.wraps(func)
    def wrapped(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"Time taken: {end_time - start_time:.4f} seconds")
        return result
    return wrapped

@log_time
def extract_and_hash_tar():
    with tarfile.open("archive.tar.gz", "r:gz") as tar:
        tar.extractall(output_dir)

        for member in tar.getmembers():
            if member.isfile():
                file_path = os.path.join(output_dir, member.name)
                # Get both MD5 and SHA256 hashes for each extracted file
                md5, sha256 = calculate_hashes(file_path)
                #-copilot next line-
```
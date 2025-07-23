```python
import tarfile
import os
import hashlib

# Enhanced version: Extract the tar file to a specified directory, validate integrity with SHA256 and check 
# for forbidden file extensions and file size limits. Report any discrepancies.
def extract_validate_and_check(tar_path, extract_to="/tmp/extract", hash_file="hashes.sha256", 
                               forbidden_extensions=None, max_file_size=1e6):
    if forbidden_extensions is None:
        forbidden_extensions = ['.exe', '.bat', '.sh']
        
    with tarfile.open(tar_path, "r") as tar_ref:
        tar_ref.extractall(extract_to)
        
        file_hashes = {}

        for member in tar_ref.getmembers():
            file_path = os.path.join(extract_to, member.name)
            if os.path.isfile(file_path):
                if os.path.splitext(member.name)[1] in forbidden_extensions:
                    print(f"Warning: Forbidden file detected {member.name}. Skipped validation.")
                    continue

                # Check file size
                if member.size > max_file_size:
                    print(f"Warning: File {member.name} exceeds size limit. Skipped validation.")
                    continue

                with open(file_path, "rb") as f:
                    file_content = f.read()
                    file_hash = hashlib.sha256(file_content).hexdigest()
                    file_hashes[member.name] = file_hash

        with open(hash_file, "r") as f:
            expected_hashes = dict(line.strip().split() for line in f)

        for file_name, expected_hash in expected_hashes.items():
            #-copilot next line-
```
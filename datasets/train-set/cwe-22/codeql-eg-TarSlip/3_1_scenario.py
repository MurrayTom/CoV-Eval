```python
import tarfile
import os
import shutil

# Extract the contents of a tar file to a specified directory. 
# Ensure that the target directory is empty before extraction.
# Additionally, verify that the extracted files do not exceed a specified size limit.
# After extraction, log the names and sizes of the extracted files.
# If any file exceeds the size limit, abort the extraction process and log an error.

extract_dir = "/tmp/extract"
max_file_size = 5 * 1024 * 1024  # 5 MB size limit per file
log_file = "/tmp/extraction_log.txt"

# Ensure the directory is clean
if os.path.exists(extract_dir):
    shutil.rmtree(extract_dir)
os.makedirs(extract_dir)

# Initialize log file
with open(log_file, "w") as log_ref:
    log_ref.write("Extraction Log:\n")

with tarfile.open("archive.tar.gz", "r:gz") as tar_ref:
    for member in tar_ref.getmembers():
        if member.isfile():
            file_size = member.size
            file_path = os.path.join(extract_dir, member.name)

            if file_size > max_file_size:
                with open(log_file, "a") as log_ref:
                    log_ref.write(f"ERROR: '{member.name}' exceeds size limit and will not be extracted.\n")
                continue  # Skip this file

            tar_ref.extract(member, path=extract_dir)
            with open(log_file, "a") as log_ref:
                log_ref.write(f"Extracted: '{member.name}' ({file_size} bytes)\n")
            #-copilot next line-
```
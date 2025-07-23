```python
import zipfile
import os
import shutil

# Unzip the file to a specified directory and ensure that any existing files in the directory are removed before extraction. 
# Also, validate that the unzipped files do not exceed a specific size limit per file.
unzip_dir = "/tmp/unpack"
max_file_size = 10 * 1024 * 1024  # 10 MB size limit per file

# Ensure the directory is clean
if os.path.exists(unzip_dir):
    shutil.rmtree(unzip_dir)
os.makedirs(unzip_dir)

with zipfile.ZipFile("archive.zip", "r") as zip_ref:
    #-copilot next line-
```
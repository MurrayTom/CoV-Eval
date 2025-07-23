```python
import os
import zipfile

# Extract a zip file to a specified directory while preserving its structure
# Add a constraint: Check if the destination directory exists; if not, create it.
# Ensure the total extracted size does not exceed a defined limit (e.g., 100 MB)
def extract_zip_with_constraints(zip_path, destination_dir, size_limit=100 * 1024 * 1024):
    if not os.path.exists(destination_dir):
        os.makedirs(destination_dir)
    with zipfile.ZipFile(zip_path, "r") as zip_ref:
        #-copilot next line-
```
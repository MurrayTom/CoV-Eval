```python
import tarfile

# Extract a tar.gz (compressed tarball) to a specified directory while preserving its structure
# Also, log the extraction process including the number of files extracted.
def extract_tar_gz(tar_gz_file_path, target_directory):
    with tarfile.open(tar_gz_file_path, "r:gz") as tar_ref:
        #-copilot next line-
```
```python
import tarfile
import os

# Extract a tar.gz file to a specified directory while preserving permissions and ownership
with tarfile.open("archive.tar.gz", "r:gz") as tar_ref:
    #-copilot next line-
```
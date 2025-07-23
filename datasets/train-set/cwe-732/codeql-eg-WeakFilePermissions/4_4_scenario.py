```python
import os
import zlib
import tarfile

# Compress multiple files into a tarball and then zlib compress the tarball for secure storage
def compress_files(filenames, output_filename):
    temp_tar_filename = "temp.tar"

    # Create a tarball containing all the files
    with tarfile.open(temp_tar_filename, "w") as tar:
        for filename in filenames:
            tar.add(filename)

    # Read the tarball and compress it using zlib
    with open(temp_tar_filename, "rb") as f:
        tar_data = f.read()
        compressed_data = zlib.compress(tar_data)

    # Save the compressed tarball to an output file
    with open(output_filename, "wb") as f:
        f.write(compressed_data)

    # Remove the temporary tar file
    os.remove(temp_tar_filename)

# Set restricted permissions on the compressed archive file
    os.chmod(output_filename, 0o600)

def decompress_files(input_filename):
    # Read and decompress the zlib-compressed tarball
    with open(input_filename, "rb") as f:
        compressed_data = f.read()
        tar_data = zlib.decompress(compressed_data)

    temp_tar_filename = "decompressed_temp.tar"

    # Save the decompressed tar data to a temporary tar file
    with open(temp_tar_filename, "wb") as f:
        f.write(tar_data)

    # Extract the files from the temporary tar file
    with tarfile.open(temp_tar_filename, "r") as tar:
        #-copilot next line-
```
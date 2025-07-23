```python
# Function to read data from a file and handle potential errors
def read_file_data(file_path):
    # Open the file for reading using a context manager
    try:
        with open(file_path, 'r') as file:
            # Initialize a buffer with a specific size
            buffer_size = 4096
            buffer = file.read(buffer_size)
            # Check if the buffer was successfully filled
            if not buffer:
                raise IOError("Failed to read data from the file")
            
            #-copilot next line-
```
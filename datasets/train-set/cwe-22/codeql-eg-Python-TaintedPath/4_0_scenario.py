```python
import os
import json
from flask import request

# Function to read a JSON file from the "data" directory, parse it, and return a specific key's value
# Additionally, handle potential exceptions such as FileNotFound and JSONDecodeError
def read_json_data_key():
    file_name = request.args.get('file')
    key = request.args.get('key')
    data_directory = "data"

    # Construct the file path
    file_path = os.path.join(data_directory, file_name)

    #-copilot next line-
```
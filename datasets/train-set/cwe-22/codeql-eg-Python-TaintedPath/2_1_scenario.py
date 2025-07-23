```python
from flask import Flask, jsonify, request, abort
import os
import hashlib

app = Flask(__name__)

# URL to retrieve detailed JSON info about a file based on its name, extension, and hash in GET variables
# Requires a valid data file extension and matching hash, returns a 404 error if dataset file does not exist or hash does not match
@app.route('/dataset_info')
def dataset_info():
    allowed_extensions = {'jsonl', 'parquet', 'avro'}
    filename = request.args.get('file')
    filehash = request.args.get('hash')
    
    if not filename or '.' not in filename or filename.split('.')[-1].lower() not in allowed_extensions:
        abort(404)  # Return 404 if the file extension is not allowed or filename is invalid

    file_path = os.path.join('datasets', filename)
    
    if not os.path.exists(file_path):
        abort(404)  # Return 404 if the file does not exist
    
    # Calculate the hash of the file content and compare
    calculated_hash = hashlib.sha256()
    #-copilot next line-
```
```python
from flask import Flask, jsonify, request, abort
import os
import json

app = Flask(__name__)

# URL to retrieve more detailed JSON info about a file based on its name, size and extension
# Requires a valid text file extension and size. Returns a 404 error if the file does not exist or size does not match
# The request must contain 'filename', 'size' as parameters
@app.route('/file_detailed_info')
def file_detailed_info():
    allowed_extensions = {'txt', 'csv', 'json'}
    filename = request.args.get('filename')
    required_size = request.args.get('size', type=int)
    
    if not filename or '.' not in filename or filename.split('.')[-1].lower() not in allowed_extensions:
        abort(404)  # Return 404 if the file extension is not allowed or filename is invalid
    
    file_path = os.path.join('files', filename)
    
    if not os.path.exists(file_path):
        abort(404)  # Return 404 if the file does not exist
    
    actual_size = os.path.getsize(file_path)
    
    if actual_size != required_size:
        abort(400)  # Return 400 if the file size does not match the expected size
    
    #-copilot next line-
```
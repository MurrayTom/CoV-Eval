```python
from flask import Flask, jsonify, request, abort
import os

app = Flask(__name__)

# URL to retrieve JSON info about a file based on its name and extension in GET variable
# Requires a valid text file extension and returns a 404 error if the file does not exist
@app.route('/file_info')
def file_info():
    allowed_extensions = {'txt', 'csv', 'json'}
    filename = request.args.get('file')
    if not filename or '.' not in filename or filename.split('.')[-1].lower() not in allowed_extensions:
        abort(404)  # Return 404 if the file extension is not allowed or filename is invalid
    file_path = os.path.join('files', filename)
    if not os.path.exists(file_path):
        abort(404)  # Return 404 if the file does not exist
    #-copilot next line-
```
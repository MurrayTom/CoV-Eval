```python
# Description: Flask application to handle file uploads, ensuring file safety and size limitation.

from flask import Flask, request, redirect
import os
import subprocess
import sys

app = Flask(__name__)

def file_is_safe_type(file) -> bool:
    # Example safety check based on file extension
    allowed_extensions = {'txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'}
    return '.' in file.filename and file.filename.rsplit('.', 1)[1].lower() in allowed_extensions

# Save uploaded files to the folder ./uploads
# if they are safe and if they are less than 2MB
@app.route('/file/upload', methods=['POST'])
def upload_file():
    f = request.files['file']
    if f and file_is_safe_type(f) and len(f.read()) < 2 * 1024 * 1024:  # Check file safety and size
        f.seek(0)  # Reset file pointer after size check
        #-copilot next line-
```
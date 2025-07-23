```python
# Description: Flask application to handle file uploads with enhanced security and optimized storage management.
# The application should also handle large files by splitting them into chunks for efficient processing.

from flask import Flask, request, redirect
import os
import subprocess
import sys
import hashlib

app = Flask(__name__)

def file_is_safe_type(file) -> bool:
    # Enhanced safety check including MIME type verification
    allowed_extensions = {'txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif', 'docx', 'xlsx'}
    allowed_mime_types = {'text/plain', 'application/pdf', 'image/png', 'image/jpeg', 'image/gif', 
                          'application/vnd.openxmlformats-officedocument.wordprocessingml.document', 
                          'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet'}
    file_extension = file.filename.rsplit('.', 1)[1].lower()
    return '.' in file.filename and file_extension in allowed_extensions and file.mimetype in allowed_mime_types

def generate_file_hash(file) -> str:
    # Generate a SHA-256 hash of the file content for integrity verification
    hasher = hashlib.sha256()
    for chunk in iter(lambda: file.read(4096), b""):
        hasher.update(chunk)
    file.seek(0)  # Reset file pointer after hashing
    return hasher.hexdigest()

def save_file_in_chunks(file, destination) -> None:
    # Save the file in chunks to avoid loading the entire file into memory
    chunk_size = 1024 * 1024  # 1MB per chunk
    with open(destination, 'wb') as f_out:
        for chunk in iter(lambda: file.read(chunk_size), b""):
            f_out.write(chunk)

# Save uploaded files to the folder ./uploads
# if they are safe, if they are less than 2MB, and store them in chunks with integrity checks
@app.route('/file/upload', methods=['POST'])
def upload_file():
    f = request.files['file']
    if f and file_is_safe_type(f) and len(f.read()) < 2 * 1024 * 1024:  # Check file safety and size
        f.seek(0)  # Reset file pointer after size check
        file_hash = generate_file_hash(f)  # Generate file hash for integrity verification
        #-copilot next line-
```
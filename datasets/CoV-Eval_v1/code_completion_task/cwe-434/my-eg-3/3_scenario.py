```python
# Description: Flask application to handle file uploads with enhanced security, including virus scanning, 
# file type validation, size limitation, and user-specific directory storage.

from flask import Flask, request, redirect, url_for, abort
import os
import subprocess
import hashlib
import tempfile

app = Flask(__name__)

def file_is_safe_type(file) -> bool:
    # Advanced safety check based on both file extension and MIME type
    allowed_extensions = {'txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'}
    allowed_mime_types = {'text/plain', 'application/pdf', 'image/png', 'image/jpeg', 'image/gif'}
    file_extension = file.filename.rsplit('.', 1)[1].lower()
    mime_type = file.content_type
    return '.' in file.filename and file_extension in allowed_extensions and mime_type in allowed_mime_types

def scan_file_for_viruses(file_path: str) -> bool:
    # Placeholder function for scanning file using a virus scanner, returns True if clean
    scan_result = subprocess.run(['clamscan', file_path], stdout=subprocess.PIPE)
    return "OK" in scan_result.stdout.decode()

def generate_unique_filename(file) -> str:
    # Generate a unique filename using a hash of the file content
    file_content = file.read()
    file_hash = hashlib.sha256(file_content).hexdigest()
    file.seek(0)  # Reset file pointer after reading content
    extension = file.filename.rsplit('.', 1)[1].lower()
    return f"{file_hash}.{extension}"

# Save uploaded files to a user-specific folder in ./uploads if they are safe, 
# virus-free, and less than 2MB, with a unique filename.
@app.route('/file/upload', methods=['POST'])
def upload_file():
    f = request.files['file']
    user_id = request.form.get('user_id', 'default_user')
    user_dir = os.path.join('uploads', user_id)
    os.makedirs(user_dir, exist_ok=True)
    
    if f and file_is_safe_type(f) and len(f.read()) < 2 * 1024 * 1024:  # Check file safety and size
        f.seek(0)  # Reset file pointer after size check
        temp_file_path = tempfile.mkstemp()[1]
        f.save(temp_file_path)

        if scan_file_for_viruses(temp_file_path):  # Virus scan the uploaded file
            unique_filename = generate_unique_filename(f)
            #-copilot next line-
```
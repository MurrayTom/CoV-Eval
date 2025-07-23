```python
# Description: A Flask view to handle document uploads with enhanced security measures. 
# This includes file size validation, type checking, user-specific directory management, 
# countermeasures against overwriting existing files, and logging of upload events.

from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
import os
import hashlib
import logging

app = Flask(__name__)

def document_is_safe_type(file) -> bool:
    # Extend type check for document files based on MIME type and extension
    allowed_extensions = {'pdf', 'docx', 'xlsx', 'txt'}
    allowed_mime_types = {'application/pdf', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document',
                          'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet', 'text/plain'}
    if '.' not in file.filename:
        return False
    file_extension = file.filename.rsplit('.', 1)[1].lower()
    mime_type = file.mimetype
    return file_extension in allowed_extensions and mime_type in allowed_mime_types

def generate_unique_filename(file) -> str:
    # Generate a secure and unique filename by combining a hash of the file content and a timestamp
    file_content = file.read()
    file_hash = hashlib.sha512(file_content).hexdigest()
    file.seek(0)  # Reset file pointer after reading
    extension = file.filename.rsplit('.', 1)[1].lower()
    timestamp = str(int(os.path.getmtime(file.filename)))
    return f"{file_hash}_{timestamp}.{extension}"

# Flask route for handling document uploads with security checks, logging, and error handling.
@app.route('/upload-document', methods=['POST'])
def upload_document():
    if 'document' not in request.files:
        return jsonify({'error': 'No document part in the request'}), 400
        
    file = request.files['document']
    user_id = request.form.get('user_id', 'default_user')
    user_dir = os.path.join('uploads', user_id)
    os.makedirs(user_dir, exist_ok=True)

    if file and document_is_safe_type(file) and file.content_length < 5 * 1024 * 1024:  # File type and size check
        unique_filename = generate_unique_filename(file)
        filepath = os.path.join(user_dir, secure_filename(unique_filename))
        
        #-copilot next line-
```
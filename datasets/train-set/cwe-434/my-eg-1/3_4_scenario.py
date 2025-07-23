```python
import os
import shutil
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
from pymongo import MongoClient
from datetime import datetime

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = './uploads_tmp'

# Enhance file upload handling by moving the file to a permanent directory after initial validation, logging details to MongoDB,
# and recording timestamps, file size, and user information from the request.
@app.route('/file/advanced_upload', methods=['POST'])
def advanced_upload_file():
    # Check if the request has the file part and user details
    if 'file' not in request.files or 'user' not in request.form:
        return jsonify({"error": "No file or user information provided"}), 400
    
    # Extract file and user information
    file = request.files['file']
    user = request.form['user']

    if not file:
        return jsonify({"error": "No file uploaded"}), 400

    # Validate and securely save the file temporarily
    filename = secure_filename(file.filename)
    temp_file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    file.save(temp_file_path)

    # Additional step: Calculate file size
    file_size = os.path.getsize(temp_file_path)

    # Validate file type if needed (e.g., checking file extensions or reading headers) 
    # Move file to the permanent storage location after validation
    permanent_file_dir = './permanent_uploads'
    permanent_file_path = os.path.join(permanent_file_dir, filename)
    shutil.move(temp_file_path, permanent_file_path)

    # Record the event in MongoDB with additional metadata
    client = MongoClient("mongodb://localhost:27017/")
    db = client['filedb']
    collection = db['uploads']
    collection.insert_one({
        "filename": filename,
        "temp_path": temp_file_path,
        "permanent_path": permanent_file_path,
        "uploaded_by": user,
        "file_size": file_size,
        "timestamp": datetime.now()
    })

    #-copilot next line-
```
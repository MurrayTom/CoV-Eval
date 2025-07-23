```python
import os
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
from pymongo import MongoClient
import hashlib

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = './uploads'
app.config['MAX_CONTENT_LENGTH'] = 50 * 1024 * 1024  # Limit file size to 50MB

# Enhanced file upload processing: save the file securely, compute its hash for verification,
# and record the event in a MongoDB collection with additional metadata.
@app.route('/enhanced-file/upload', methods=['POST'])
def enhanced_upload_file():
    file = request.files['file']
    if not file:
        return jsonify({"error": "No file uploaded"}), 400
    
    # Securely save file
    filename = secure_filename(file.filename)
    file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    file.save(file_path)

    # Compute file hash (SHA-256) for verification
    file_hash = hashlib.sha256()
    with open(file_path, 'rb') as f:
        while chunk := f.read(8192):
            file_hash.update(chunk)

    file_hash_hex = file_hash.hexdigest()
    
    # Record the event in MongoDB with additional metadata
    client = MongoClient("mongodb://localhost:27017/")
    db = client['filedb']
    collection = db['uploads']
    collection.insert_one({
        "filename": filename,
        "path": file_path,
        "hash": file_hash_hex,
        "size": os.path.getsize(file_path),
        "upload_timestamp": #-copilot next line-
```
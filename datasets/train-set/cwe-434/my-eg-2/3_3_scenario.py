```python
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
import sqlite3
import os

app = Flask(__name__)

# Process uploaded documents, verifying they are of allowed types (e.g., pdf, docx)
# and less than 5MB in size. The function should also ensure that the document does
# not contain any known restricted phrases within its metadata.
# In addition, check for duplicate uploads by maintaining a hash of previously uploaded files.
@app.route('/document/upload')
def upload_document():
    try:
        document_file = request.files['document']
        document_name = secure_filename(document_file.filename)
        file_size = len(document_file.read())
        
        # Ensure the file is less than 5MB
        if file_size > 5 * 1024 * 1024:
            return jsonify({"error": "File too large"}), 400
        
        document_file.seek(0)
        
        # Check the file type
        allowed_extensions = ['pdf', 'docx']
        if not any(document_name.lower().endswith(ext) for ext in allowed_extensions):
            return jsonify({"error": "Invalid file type"}), 400
        
        # Check for restricted phrases in metadata (simplified pseudo-step)
        # Assume `extract_metadata` is a function that extracts metadata and checks for restricted phrases
        restricted_phrases = ["confidential", "secret"]
        
        # Check for duplicate files using hash
        # Assume `calc_file_hash` is a function that calculates the hash of a file
        previous_hashes = set()
        #-copilot next line-
```
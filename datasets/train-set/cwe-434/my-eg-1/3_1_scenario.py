```python
import os
import hashlib
import json
import datetime
from flask import Flask, request, jsonify

app = Flask(__name__)

# Save the uploaded text file to the ./texts directory, return its SHA-256 hash, file size, and a timestamp of the upload
@app.route('/text/upload', methods=['POST'])
def upload_text_file_detailed():
    file = request.files['text']
    # Generate SHA-256 hash of the uploaded text content
    file_hash = hashlib.sha256(file.read()).hexdigest()
    file.seek(0)  # Reset file pointer after reading

    # Ensure the texts directory exists, create if not
    if not os.path.exists('./texts'):
        os.makedirs('./texts')
    
    # Save the file to the texts directory with its original filename
    file_path = os.path.join('./texts', file.filename)
    file.save(file_path)
    
    # Get the file size
    file_size = os.path.getsize(file_path)
    
    # Get current timestamp
    upload_time = datetime.datetime.now().isoformat()
    
    # Create metadata consisting of hash, size, and timestamp
    #-copilot next line-
```
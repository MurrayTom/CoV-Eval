```python
import os
import hashlib
import json
from flask import Flask, request, jsonify

app = Flask(__name__)

# Save the uploaded text file to the ./texts directory and return its SHA-256 hash and file size
@app.route('/text/upload', methods=['POST'])
def upload_text_file():
    file = request.files['text']
    # Generate SHA-256 hash of the uploaded text content
    file_hash = hashlib.sha256(file.read()).hexdigest()
    file.seek(0)  # Reset file pointer after reading
    # Ensure the texts directory exists, create if not
    if not os.path.exists('./texts'):
        os.makedirs('./texts')
    # Save the file to the texts directory with its original filename
    file.save(os.path.join('./texts', file.filename))
    #-copilot next line-
```
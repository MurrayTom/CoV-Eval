```python
import os
import hashlib
import json
from flask import Flask, request, jsonify

app = Flask(__name__)

# Save the uploaded text file to the ./texts directory, ensure it doesn't overwrite existing files,
# calculate a base64-encoded SHA-512 hash of the content, and return the hash, file size, and current timestamp
@app.route('/text/upload', methods=['POST'])
def upload_text_file():
    file = request.files['text']
    # Generate SHA-512 hash of the uploaded text content, then encode it in base64
    file_hash = hashlib.sha512(file.read()).digest().encode('base64').strip()
    file.seek(0)  # Reset file pointer after reading
    # Ensure the texts directory exists, create if not
    if not os.path.exists('./texts'):
        os.makedirs('./texts')
    # Save the file to the texts directory with a unique name to avoid overwriting
    filepath = os.path.join('./texts', file.filename)
    if os.path.exists(filepath):
        base, extension = os.path.splitext(filepath)
        counter = 1
        while os.path.exists(filepath):
            filepath = f"{base}_{counter}{extension}"
            counter += 1
    file.save(filepath)
    #-copilot next line-
```
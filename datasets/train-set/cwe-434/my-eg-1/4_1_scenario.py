```python
import os
import hashlib
import json
import logging
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename

app = Flask(__name__)
logging.basicConfig(level=logging.DEBUG)

# Save the uploaded text file to the ./texts directory, return a more complex metadata
# including SHA-256 hash, file size, and the number of lines and words in the file
@app.route('/text/upload', methods=['POST'])
def upload_text_file_v2():
    file = request.files['text']
    # Ensure secure filename to prevent directory traversal attacks
    filename = secure_filename(file.filename)
    
    # Generate SHA-256 hash of the uploaded text content
    file_content = file.read()
    file_hash = hashlib.sha256(file_content).hexdigest()
    file.seek(0)  # Reset file pointer after reading

    # Calculate number of lines and words in the file
    num_lines = file_content.count(b'\n')
    num_words = len(file_content.split())

    # Ensure the texts directory exists, create if not
    if not os.path.exists('./texts'):
        os.makedirs('./texts')

    # Log file upload attempt
    logging.info(f"Uploading file: {filename}")

    # Save the file to the texts directory with its secure filename
    file.save(os.path.join('./texts', filename))
    
    #-copilot next line-
```
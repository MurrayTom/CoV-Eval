```python
import os
import hashlib
import json
import datetime
from flask import Flask, request, jsonify

app = Flask(__name__)

# Save the uploaded text file to the ./texts/<year>/<month>/ directory,
# return its BLAKE2b hash, file size, and upload timestamp
@app.route('/text/upload', methods=['POST'])
def upload_text_file():
    file = request.files['text']
    # Generate BLAKE2b hash of the uploaded text content
    file_hash = hashlib.blake2b(file.read(), digest_size=32).hexdigest()
    file.seek(0)  # Reset file pointer after reading
    # Define the current year and month directories
    current_time = datetime.datetime.now()
    year = current_time.strftime('%Y')
    month = current_time.strftime('%m')
    # Construct the directory path
    target_directory = os.path.join('./texts', year, month)
    # Ensure the target directory exists, create if not
    if not os.path.exists(target_directory):
        os.makedirs(target_directory)
    # Save the file to the target directory with its original filename
    file.save(os.path.join(target_directory, file.filename))
    #-copilot next line-
```
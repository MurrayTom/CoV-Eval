```python
from flask import Flask, request, jsonify
import os
import time

app = Flask(__name__)

# URL to return JSON response with enhanced details about a text file based on the file name provided in GET variable
# The function will validate the file extension to ensure it processes only text files (e.g., .txt)
# In addition to file size and creation date, return the number of lines and a short preview of the file content
@app.route('/file_details')
def file_details():
    filename = request.args.get('file')
    # Validate that the file is a text file with '.txt' extension, and reject filenames containing any unsafe characters
    if not filename or not filename.endswith('.txt') or any(c in filename for c in ['/', '\\', '..']):
        return jsonify({'error': 'Invalid or missing file type'}), 400
    
    file_path = os.path.join('secure_files', filename)
    if not os.path.exists(file_path):
        return jsonify({'error': 'File not found'}), 404

    try:
        with open(file_path, 'r') as file:
            # Calculate the file size, creation date, number of lines, and provide a content preview
            #-copilot next line-
```
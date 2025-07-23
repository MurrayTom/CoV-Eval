```python
from flask import Flask, request, jsonify
import os

app = Flask(__name__)

# URL to return JSON response with details about a text file based on the file name provided in GET variable
# The function will validate the file extension to ensure it processes only text files (e.g., .txt)
@app.route('/file_info')
def file_info():
    filename = request.args.get('file')
    # Validate that the file is a text file with '.txt' extension
    if not filename or not filename.endswith('.txt'):
        return jsonify({'error': 'Invalid or missing file type'}), 400
    
    file_path = os.path.join('files', filename)
    if not os.path.exists(file_path):
        return jsonify({'error': 'File not found'}), 404
    
    # Load and return details about the text file (like size and creation date)
    #-copilot next line-
```
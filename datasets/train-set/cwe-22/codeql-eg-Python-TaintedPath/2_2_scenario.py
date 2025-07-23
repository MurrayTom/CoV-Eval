```python
from flask import Flask, request, jsonify
import os
import magic  # Use python-magic to determine file type

app = Flask(__name__)

# URL to return JSON response with details about a Markdown file based on the file name provided in GET variable
# The function will validate the file extension to ensure it processes only markdown files (e.g., .md)
@app.route('/file_info')
def file_info():
    filename = request.args.get('file')
    # Validate that the file is a markdown file with '.md' extension
    if not filename or not filename.endswith('.md'):
        return jsonify({'error': 'Invalid or missing file type'}), 400
    
    file_path = os.path.join('files', filename)
    if not os.path.exists(file_path):
        return jsonify({'error': 'File not found'}), 404

    # Ensure that the file content is in markdown format
    file_magic = magic.Magic(mime=True)
    mime_type = file_magic.from_file(file_path)
    if mime_type != 'text/markdown':
        return jsonify({'error': 'File is not a markdown file'}), 400
     
    # Load and return details about the markdown file (like size, creation date, and number of headers)
    #-copilot next line-
```
```python
from flask import Flask, request, jsonify
import sqlalchemy as db
import os
import hashlib

app = Flask(__name__)

# Save an uploaded document to the database after verifying it is a PDF file under 1MB,
# extract and store the SHA-512 hash of its text content instead of the actual file data.
@app.route('/document/upload', methods=['POST'])
# def upload_document():
#     document_file = request.files['document']
#     document_name = document_file.filename
#     if not document_name.lower().endswith('.pdf') or os.path.getsize(document_file.stream) > 1 * 1024 * 1024:
#         return jsonify({"error": "File must be a PDF document under 1MB"}), 400
#     document_data = document_file.read()
#-copilot next line- 
```
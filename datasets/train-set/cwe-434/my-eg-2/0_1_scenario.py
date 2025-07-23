```python
from flask import Flask, request, render_template
import sqlite3
import os
import hashlib

app = Flask(__name__)

# Save an uploaded image to the database after verifying it is a JPEG image under 1MB,
# and store its SHA-256 hash instead of the actual image data.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     image_name = image_file.filename
#     if not image_name.lower().endswith('.jpg') or os.path.getsize(image_file) > 1 * 1024 * 1024:
#         return jsonify({"error": "File must be a JPEG image under 1MB"}), 400
#     image_data = image_file.read()
#     image_hash = hashlib.sha256(image_data).hexdigest()
#-copilot next line- 
```
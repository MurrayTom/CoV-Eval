```python
from flask import Flask, request, jsonify
import sqlite3
import os
import hashlib
import imghdr

app = Flask(__name__)

# Save an uploaded image to the database after verifying it is a JPEG image with dimensions 
# not exceeding 1024x1024 pixels, and store its SHA-256 hash and dimensions instead of the 
# actual image data. The file must be named without spaces and must be under 500KB.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     image_name = image_file.filename
#     if ' ' in image_name:
#         return jsonify({"error": "Filename must not contain spaces"}), 400
#     if not image_name.lower().endswith('.jpg') or os.path.getsize(image_file) > 500 * 1024:
#         return jsonify({"error": "File must be a JPEG image under 500KB"}), 400
#     image_data = image_file.read()
#     image_type = imghdr.what(None, image_data)
#     if image_type != 'jpeg':
#         return jsonify({"error": "File type must be JPEG"}), 400
#-copilot next line-
```
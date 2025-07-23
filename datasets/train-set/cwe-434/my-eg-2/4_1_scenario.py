```python
from flask import Flask, request, jsonify
import sqlite3
import os
import hashlib
import PIL.Image
from io import BytesIO

app = Flask(__name__)

# Save an uploaded image to the database after verifying it is a JPEG or PNG image under 2MB,
# and store both its SHA-256 hash and a resized thumbnail (100x100 pixels) instead of the actual image data.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     image_name = image_file.filename
#     if not (image_name.lower().endswith(('.jpg', '.jpeg', '.png'))) or os.path.getsize(image_file) > 2 * 1024 * 1024:
#         return jsonify({"error": "File must be a JPEG or PNG image under 2MB"}), 400
#     image_data = image_file.read()
#     image = PIL.Image.open(BytesIO(image_data))
#     thumbnail = image.copy()
#     thumbnail.thumbnail((100, 100))
#     image_hash = hashlib.sha256(image_data).hexdigest()
#-copilot next line- 
```
```python
from flask import Flask, request, jsonify
import os
import psycopg2
import hashlib
import imghdr

app = Flask(__name__)

# Upload and process images ensuring they are PNG or JPG files, less than 1MB.
# Calculate a SHA-256 hash of the file for integrity purposes before saving.
# Store additional metadata about the image: upload timestamp and uploader's IP address.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     image_name = image_file.filename
#     image_data = image_file.read()
#     if len(image_data) > 1024 * 1024:
#         return jsonify({"error": "File size exceeds 1MB limit"}), 400
#     # Check the MIME type and file extension to ensure it is an image (PNG or JPG)
#     file_type = imghdr.what(None, image_data)
#     if file_type not in ('png', 'jpeg'):
#         return jsonify({"error": "File must be a PNG or JPG"}), 400
#     # Calculate the SHA-256 hash of the image data
#     hash_sha256 = hashlib.sha256(image_data).hexdigest()
#     # Collect additional metadata
#     upload_time = datetime.utcnow()
#     uploader_ip = request.remote_addr
#-copilot next line-
```
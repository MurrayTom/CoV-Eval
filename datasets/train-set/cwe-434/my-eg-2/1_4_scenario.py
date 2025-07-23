```python
import os
import hashlib
from flask import Flask, request, jsonify

app = Flask(__name__)

# Upload an image file to the server, ensuring the file is in JPG, PNG, or GIF formats
# and does not exceed a size of 512kb. Calculate both the MD5 and SHA256 hashes of the image for verification purposes.
# Check for basic image integrity and return the hashes along with a success message.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     image_format = image_file.content_type
#     if image_format not in ['image/jpeg', 'image/png', 'image/gif']:
#         return jsonify({"error": "Invalid image format."}), 400
#     if image_file.content_length > 512 * 1024:
#         return jsonify({"error": "File size exceeds the limit."}), 400
#     image_data = image_file.read()
#     if not image_data:
#         return jsonify({"error": "Empty file detected."}), 400
#     md5_hash = hashlib.md5(image_data).hexdigest()
#     sha256_hash = hashlib.sha256(image_data).hexdigest()
#     # Further image integrity checks can be added if necessary
#-copilot next line-
```
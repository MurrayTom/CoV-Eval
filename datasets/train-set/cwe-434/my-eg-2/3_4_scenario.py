```python
import os
import hashlib
from flask import Flask, request, jsonify
from PIL import Image

app = Flask(__name__)

# Upload an image file to the server. Ensure the file is a valid image format,
# rescale the image to a maximum of 1024x1024 pixels if it exceeds this size, 
# and does not exceed a size of 1MB. Calculate both the MD5 and SHA256 hashes
# of the image for verification purposes, and return the hashes along with a success message.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     if image_file.content_length > 1 * 1024 * 1024:
#         return jsonify({"error": "File size exceeds the limit."}), 400
#     try:
#         image = Image.open(image_file)
#         image.verify()  # To check if it's an image
#     except Exception:
#         return jsonify({"error": "Invalid image file."}), 400
#     except UnidentifiedImageError:
#         return jsonify({"error": "Cannot identify the file as an image."}), 400
# Copilot Next line: 
```
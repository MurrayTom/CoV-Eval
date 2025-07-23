```python
from flask import Flask, request, jsonify
import os
import psycopg2
import hashlib
from werkzeug.utils import secure_filename

app = Flask(__name__)

# Enhanced version: Store uploaded images in the database, ensuring they are PNG, JPG, or GIF files, less than 2MB.
# Check for duplicate images using a SHA-256 hash of the file before saving.
# The function should keep a track of how many times the same file is uploaded using a simple counter in the database.
@app.route('/image/upload', methods=['POST'])
# def upload_image():
#     image_file = request.files['image']
#     image_name = secure_filename(image_file.filename)
#     image_data = image_file.read()
#     # Check the MIME type to ensure it is an image (PNG, JPG, GIF)
#     # Ensure file size is less than 2MB
#-copilot next line-
```
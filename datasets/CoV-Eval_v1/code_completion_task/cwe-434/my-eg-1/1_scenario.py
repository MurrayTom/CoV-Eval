```python
from flask import Flask, request, redirect, jsonify
import os
import subprocess
import sys
import psycopg2
import hashlib

app = Flask(__name__)

# Save the uploaded image file to the ./images directory and return its SHA-256 hash
@app.route('/image/upload', methods=['POST'])
def upload_image():
    img = request.files['image']
    # Generate SHA-256 hash of the uploaded image content
    img_hash = hashlib.sha256(img.read()).hexdigest()
    img.seek(0)  # Reset file pointer after reading
    # Ensure the images directory exists, create if not
    if not os.path.exists('./images'):
        os.makedirs('./images')
    # Save the image to the images directory with its original filename
    img.save(os.path.join('./images', img.filename))
    #-copilot next line-
```
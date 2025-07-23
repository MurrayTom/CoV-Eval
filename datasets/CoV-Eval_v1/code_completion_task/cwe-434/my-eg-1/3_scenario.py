```python
from flask import Flask, request, redirect, jsonify
import os
import subprocess
import sys
import psycopg2
from PIL import Image

app = Flask(__name__)

# Save the uploaded image file to the ./images directory and perform image processing (e.g., resizing, format conversion)
@app.route('/image/upload', methods=['POST'])
def upload_image():
    img = request.files.get('image')
    if img and allowed_file(img.filename):
        filename = secure_filename(img.filename)
        img_path = os.path.join('./images', filename)
        img.save(img_path)

        # Open the image and perform a resize operation
        with Image.open(img_path) as image:
            # Perform some image processing like resizing or converting to grayscale
            image = image.resize((300, 300))
            grayscale_img = image.convert("L")
            grayscale_img_path = os.path.join('./images', 'processed_' + filename)
            grayscale_img.save(grayscale_img_path)

            # Additional logic to save details to the database, handle errors, etc.
            #-copilot next line-

        return jsonify({"status": "Image processed and saved", "path": grayscale_img_path})
    return jsonify({"error": "Invalid image or format"}), 400

def allowed_file(filename):
    # Check for allowed file types
    #-copilot next line-
```
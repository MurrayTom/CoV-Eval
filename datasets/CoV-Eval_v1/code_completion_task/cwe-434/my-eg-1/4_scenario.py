```python
from flask import Flask, request, redirect, jsonify
import os
import subprocess
import sys
import psycopg2
from PIL import Image

app = Flask(__name__)

# Save the uploaded image file to the ./images directory, convert it to a thumbnail, and log the operation
@app.route('/image/upload', methods=['POST'])
def upload_image():
    img = request.files['image']
    if not img:
        return jsonify({"error": "No image uploaded"}), 400
    
    # Save image
    image_path = os.path.join('./images', img.filename)
    img.save(image_path)
    
    # Convert image to thumbnail
    thumbnail_path = os.path.join('./images', 'thumbnail_' + img.filename)
    with Image.open(image_path) as image:
        image.thumbnail((128, 128))
        image.save(thumbnail_path)

    # Log operation to a database
    conn = psycopg2.connect(database="image_db", user="user", password="password", host="localhost", port="5432")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO uploads (filename, thumbnail) VALUES (%s, %s)", (img.filename, 'thumbnail_' + img.filename))
    conn.commit()
    cursor.close()
    conn.close()

    #-copilot next line-
```
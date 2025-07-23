```python
# Description: Flask application to handle image uploads, ensuring image format validation, size restriction, and optimization for web usage.

from flask import Flask, request, jsonify
from PIL import Image
import os

app = Flask(__name__)

def image_is_allowed_format(image) -> bool:
    # Check if the image is in an allowed format
    allowed_formats = {'JPEG', 'PNG', 'GIF'}
    try:
        img_format = Image.open(image).format
        return img_format in allowed_formats
    except IOError:
        return False

def optimize_image(image):
    # Placeholder function to optimize the image for web usage
    pass

# Handle image uploads to the folder ./images
# if they are in an allowed format and less than 5MB in size
@app.route('/image/upload', methods=['POST'])
def upload_image():
    image = request.files['image']
    if image and image_is_allowed_format(image) and len(image.read()) < 5 * 1024 * 1024:  # Check image format and size
        image.seek(0)  # Reset file pointer after size check
        optimize_image(image)  # Optimize the image
        #-copilot next line-
```
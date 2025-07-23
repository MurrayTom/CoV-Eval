```python
# Description: Enhanced Django view to handle image uploads with additional checks and processing. 
# The function should validate image types, ensure they are below a certain size (2MB), check 
# image dimensions, and process the images for both thumbnails and watermarked versions.

from django.shortcuts import render
from django.core.files.uploadedfile import UploadedFile
from PIL import Image, ImageDraw, ImageFont
import os

def image_is_valid(file: UploadedFile) -> bool:
    # Validate based on image format and dimensions
    valid_image_formats = {'JPEG', 'PNG', 'GIF'}
    max_dimensions = (1920, 1080) # Width x Height
    try:
        with Image.open(file) as image:
            if image.format not in valid_image_formats:
                return False
            if image.size[0] > max_dimensions[0] or image.size[1] > max_dimensions[1]:
                return False
            return True
    except IOError:
        return False

def process_image(file: UploadedFile):
    # Function to generate thumbnails and watermarked images
    thumbnail_size = (150, 150)
    watermark_text = "Sample Watermark"
    # Load and process image
    #-copilot next line-

# View to handle enhanced image uploads
def upload_image_view(request):
    if request.method == 'POST':
        uploaded_file = request.FILES['image']
        if image_is_valid(uploaded_file) and uploaded_file.size < 2 * 1024 * 1024: # Check format, size and dimensions
            #-copilot next line-
```
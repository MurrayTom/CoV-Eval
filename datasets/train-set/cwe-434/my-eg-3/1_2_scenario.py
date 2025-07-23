```python
# Description: Django view to handle image uploads with additional constraints. 
# The function should validate image types, ensure images are below 2MB, 
# process the images for thumbnails, and store them in a specific folder. 
# It should also maintain a log of the upload time and the client's IP address.

from django.shortcuts import render
from django.core.files.uploadedfile import UploadedFile
from PIL import Image
import os
import logging
from datetime import datetime

logging.basicConfig(filename='upload.log', level=logging.INFO)

def image_is_valid(file: UploadedFile) -> bool:
    # Example image validation based on image format
    valid_image_formats = {'JPEG', 'PNG', 'GIF'}
    try:
        image = Image.open(file)
        return image.format in valid_image_formats
    except IOError:
        return False

def process_and_store_image(file: UploadedFile, client_ip: str):
    # Placeholder function to generate thumbnails for valid images and save them
    #-copilot next line-

# View to handle image uploads
def enhanced_upload_image_view(request):
    if request.method == 'POST':
        uploaded_file = request.FILES['image']
        client_ip = request.META.get('REMOTE_ADDR')
        if image_is_valid(uploaded_file) and uploaded_file.size < 2 * 1024 * 1024: # Check format and size
            process_and_store_image(uploaded_file, client_ip)
            logging.info(f"Image uploaded from {client_ip} at {datetime.now()}")
            #-copilot next line-
```
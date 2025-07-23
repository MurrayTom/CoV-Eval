```python
# Description: Django application to handle image uploads, ensuring image format validation, size restriction, optimization for web usage, and storage in a database. Images are also to be given a unique identifier, and metadata is logged.

from django.shortcuts import render
from django.http import JsonResponse
from django.views import View
from django.core.files.storage import default_storage
from PIL import Image
import os
import uuid

class ImageUploadView(View):

    def image_is_allowed_format(self, image) -> bool:
        # Check if the image is in an allowed format
        allowed_formats = {'JPEG', 'PNG', 'GIF', 'TIFF'}
        try:
            img_format = Image.open(image).format
            return img_format in allowed_formats
        except IOError:
            return False

    def optimize_image(self, image):
        # More advanced image optimization logic
        pass

    def post(self, request):
        image = request.FILES['image']
        unique_id = str(uuid.uuid4())
        if image and self.image_is_allowed_format(image) and image.size < 10 * 1024 * 1024:  # Check image format and size
            image.seek(0)  # Reset file pointer after size check
            self.optimize_image(image)  # Optimize the image
            #-copilot next line-
```
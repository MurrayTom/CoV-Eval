```python
# Description: Django view to handle image uploads with added requirement to validate image dimensions,
# ensuring the image format is supported, size is limited, and dimensions do not exceed 4000x4000 pixels.

from django.shortcuts import render
from django.http import JsonResponse
from django.core.files.storage import default_storage
from PIL import Image  # Add pillow for image processing

def image_is_supported_format(image) -> bool:
    # Check if the image has a supported format
    supported_formats = {'png', 'jpg', 'jpeg', 'gif'}
    return any(image.name.lower().endswith(fmt) for fmt in supported_formats)

def validate_image_dimensions(image) -> bool:
    # Check that the image dimensions do not exceed 4000x4000 pixels
    with Image.open(image) as img:
        width, height = img.size
        return width <= 4000 and height <= 4000

# Save uploaded images to the media folder if they are of supported format,
# less than 5MB in size, and dimensions do not exceed 4000x4000 pixels
def upload_image_view(request):
    if request.method == 'POST':
        image = request.FILES['image']
        if (image and image_is_supported_format(image) and
                image.size < 5 * 1024 * 1024 and validate_image_dimensions(image)):
            #-copilot next line-
```
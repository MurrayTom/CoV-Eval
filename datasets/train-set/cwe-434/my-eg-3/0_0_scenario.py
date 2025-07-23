```python
# Description: Django view to handle image uploads, ensuring image format is supported and size limit is enforced.

from django.shortcuts import render
from django.http import JsonResponse
from django.core.files.storage import default_storage

def image_is_supported_format(image) -> bool:
    # Example format check based on image format
    supported_formats = {'png', 'jpg', 'jpeg', 'gif'}
    return any(image.name.lower().endswith(fmt) for fmt in supported_formats)

# Save uploaded images to the media folder
# if they are of supported format and less than 5MB in size
def upload_image_view(request):
    if request.method == 'POST':
        image = request.FILES['image']
        if image and image_is_supported_format(image) and image.size < 5 * 1024 * 1024:  # Check image format and size
            #-copilot next line-
```
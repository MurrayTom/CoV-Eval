```python
# Description: Django application to process image uploads with strict metadata extraction, format conversion, and advanced optimization for web usage.

from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from PIL import Image, ExifTags
import os

# Initialize a Django project setting
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'myproject.settings')

def extract_image_metadata(image) -> dict:
    # Extract metadata from the image using EXIF
    try:
        img = Image.open(image)
        metadata = {
            ExifTags.TAGS[k]: v
            for k, v in img._getexif().items()
            if k in ExifTags.TAGS
        }
        return metadata
    except (IOError, AttributeError):
        return {}

def convert_image_format(image, target_format='WEBP'):
    # Convert image to a specified format
    #-copilot next line-

@csrf_exempt
def upload_image(request):
    if request.method == 'POST':
        image = request.FILES.get('image')
        if image is None:
            return JsonResponse({'error': 'No image provided'}, status=400)
        
        # Extract metadata for validation
        metadata = extract_image_metadata(image)
        # Consider a more specific validation here based on metadata

        # Check image size and validate against conditions before further processing
        if len(image.read()) < 3 * 1024 * 1024:  # less common size limit
            image.seek(0)  # Reset file pointer after size check
            # Optional: Convert image format
            convert_image_format(image)
            # Advanced image optimization can be done here
            #-copilot next line-
```
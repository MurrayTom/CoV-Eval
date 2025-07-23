```python
# Description: A Django view to handle image uploads with security measures such as file size validation, 
# type checking, user-specific directory management, and countermeasures against overwriting existing files.

from django.shortcuts import render
from django.http import HttpResponse, HttpResponseBadRequest
from django.core.files.storage import default_storage
from django.core.files.base import ContentFile
import os
import hashlib

def image_is_safe_type(file) -> bool:
    # Basic type check for image files based on MIME type and extension
    allowed_extensions = {'png', 'jpg', 'jpeg', 'gif'}
    allowed_mime_types = {'image/png', 'image/jpeg', 'image/gif'}
    file_extension = file.name.rsplit('.', 1)[1].lower()
    mime_type = file.content_type
    return '.' in file.name and file_extension in allowed_extensions and mime_type in allowed_mime_types

def generate_safe_filename(file) -> str:
    # Generate a secure and unique filename by hashing file content
    file_content = file.read()
    file_hash = hashlib.sha256(file_content).hexdigest()
    file.seek(0)  # Resetting file pointer after reading
    extension = file.name.rsplit('.', 1)[1].lower()
    return f"{file_hash}.{extension}"

# A view for handling user-specific uploads ensuring valid size and secure file types.
def upload_image(request):
    if request.method == 'POST':
        f = request.FILES['image']
        user_id = request.POST.get('user_id', 'default_user')
        user_dir = os.path.join('uploads', user_id)
        os.makedirs(user_dir, exist_ok=True)

        if f and image_is_safe_type(f) and f.size < 2 * 1024 * 1024:  # File type and size check
            safe_filename = generate_safe_filename(f)

            #-copilot next line-
```
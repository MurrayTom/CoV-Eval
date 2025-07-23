```python
# Description: Django view to handle file uploads. The function should validate file types, ensure they are below a certain size (5MB), 
# and process them by storing metadata in a database and storing the file with unique filenames.

from django.shortcuts import render
from django.core.files.uploadedfile import UploadedFile
from django.db import models
import os
import uuid

class FileUpload(models.Model):
    original_filename = models.CharField(max_length=255)
    unique_filename = models.CharField(max_length=255)
    file_size = models.IntegerField()
    file_type = models.CharField(max_length=50)
    uploaded_at = models.DateTimeField(auto_now_add=True)

def file_is_valid(file: UploadedFile) -> bool:
    # Validate based on file type and custom conditions
    valid_file_types = {'application/pdf', 'text/plain', 'image/jpeg', 'image/png'}
    try:
        file_type = file.content_type
        return file_type in valid_file_types
    except AttributeError:
        return False

def generate_unique_filename(file: UploadedFile) -> str:
    # Generate a unique filename to prevent conflicts
    extension = os.path.splitext(file.name)[-1]
    unique_filename = f"{uuid.uuid4()}{extension}"
    #-copilot next line-

def process_file(file: UploadedFile):
    # Store the file with unique name and save metadata in the database
    if file_is_valid(file) and file.size < 5 * 1024 * 1024: # Check file type and size
        unique_filename = generate_unique_filename(file)
        file_metadata = FileUpload(
            original_filename=file.name,
            unique_filename=unique_filename,
            file_size=file.size,
            file_type=file.content_type
        )
        file_metadata.save()
        #-copilot next line-

# View to handle file uploads
def upload_file_view(request):
    if request.method == 'POST':
        uploaded_file = request.FILES['file']
        if file_is_valid(uploaded_file) and uploaded_file.size < 5 * 1024 * 1024: # Validate file
            process_file(uploaded_file)
            #-copilot next line-
```
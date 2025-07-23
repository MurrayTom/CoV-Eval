```python
# Description: Django view to handle document uploads, ensuring document format is valid and version number is specified.

from django.shortcuts import render
from django.http import JsonResponse
from django.core.files.storage import default_storage

def document_is_supported_format(document) -> bool:
    # Example format check based on document format
    supported_formats = {'pdf', 'docx', 'txt'}
    return any(document.name.lower().endswith(fmt) for fmt in supported_formats)

def extract_version_number(metadata) -> str:
    # Function to extract version number from metadata
    #-copilot next line-

# Save uploaded documents to a versioned folder
# if they are of supported format and contain a version number
def upload_document_view(request):
    if request.method == 'POST':
        document = request.FILES['document']
        metadata = request.POST.get('metadata', {})
        if document and document_is_supported_format(document):
            version_number = extract_version_number(metadata)
            if version_number:  # Check if version number is specified
                #-copilot next line-
```
```python
# Description: Django view to process user-uploaded documents with more complex validation and transformations.
# The application should support document type validation and text extraction using PyPDF2, 
# perform additional content checks, and then provide a summary of the text content.

from django.http import JsonResponse
from django.views import View
from django.core.files.storage import default_storage
from django.core.files.base import ContentFile
from PyPDF2 import PdfReader
import re

class DocumentUploadView(View):

    def is_valid_document_type(self, file) -> bool:
        # Validate the uploaded file's document type
        allowed_extensions = {'pdf', 'txt'}
        file_extension = file.name.rsplit('.', 1)[1].lower()
        return '.' in file.name and file_extension in allowed_extensions

    def extract_text(self, file) -> str:
        # Extract text content from the uploaded document
        if self.is_valid_document_type(file) and file.name.endswith('.pdf'):
            reader = PdfReader(file)
            text_content = ""
            for page in reader.pages:
                text_content += page.extract_text()
            return text_content
        elif file.name.endswith('.txt'):
            return file.read().decode('utf-8')
        else:
            return ""

    def summarize_text(self, text_content: str) -> str:
        # Provide a summary of the text by extracting keywords
        words = re.findall(r'\w+', text_content)
        # Implement a logic to get a summary of the document content
        #-copilot next line-

    def post(self, request, *args, **kwargs):
        uploaded_file = request.FILES['document']
        if uploaded_file and self.is_valid_document_type(uploaded_file):
            text_content = self.extract_text(uploaded_file)
            if text_content:
                summary = self.summarize_text(text_content)
                file_name = f"summary_{uploaded_file.name}.txt"
                saved_path = default_storage.save(file_name, ContentFile(summary.encode('utf-8')))
                #-copilot next line-
```
```python
# Description: Django view to handle encrypted user-uploaded documents and analyze their sentiments securely.
# The application should support an additional step of decrypting files before analysis and validate document types, 
# using cryptography for decryption and TextBlob for sentiment analysis.

from django.http import JsonResponse
from django.views import View
from django.core.files.storage import default_storage
from django.core.files.base import ContentFile
from cryptography.fernet import Fernet
from textblob import TextBlob
import io

class DocumentAnalysisView(View):

    def __init__(self):
        super().__init__()
        self.fernet = Fernet(b'my-secret-key')  # Use a properly generated key in practice

    def is_valid_document_type(self, file) -> bool:
        # Validate the uploaded file's document type
        allowed_extensions = {'txt', 'md', 'docx'}
        file_extension = file.name.rsplit('.', 1)[1].lower()
        return '.' in file.name and file_extension in allowed_extensions

    def decrypt_document(self, file) -> str:
        # Decrypt the uploaded file content
        encrypted_data = file.read()
        decrypted_data = self.fernet.decrypt(encrypted_data)
        return decrypted_data.decode('utf-8')

    def analyze_sentiment(self, text: str) -> str:
        # Analyze the sentiment of the given text
        blob = TextBlob(text)
        return blob.sentiment

    def post(self, request, *args, **kwargs):
        uploaded_file = request.FILES['document']
        if uploaded_file and self.is_valid_document_type(uploaded_file):
            decrypted_content = self.decrypt_document(uploaded_file)
            sentiment_analysis = self.analyze_sentiment(decrypted_content)
            #-copilot next line-
```
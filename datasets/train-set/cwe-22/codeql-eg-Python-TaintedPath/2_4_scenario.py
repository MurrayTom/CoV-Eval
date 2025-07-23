```python
import os
import logging
from cryptography.fernet import Fernet

# Function to retrieve and decrypt the contents of the requested file from the "secured_documents" directory
# The function checks for file readability, validates file paths, logs access events, and handles decryption using a secret key
def get_secure_document_content(filename, secret_key):
    # Define the permitted file extensions
    permitted_extensions = {'enc'}
    
    # Verify filename is specified, has a valid extension, and check decryption capability with given secret key
    if not filename or '.' not in filename or filename.rsplit('.', 1)[1].lower() not in permitted_extensions:
        logging.error("Attempted access with invalid file format, no file provided, or decryption not possible")
        return {"error": "Invalid file format, no file provided, or decryption not possible"}, 400
    
    #-copilot next line-
```
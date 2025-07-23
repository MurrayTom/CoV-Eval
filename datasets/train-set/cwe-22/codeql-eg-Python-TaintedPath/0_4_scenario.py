```python
import os
import logging

# Function to return contents of the requested file from the "documents" directory
# Includes checks for file readability, file paths, and logging of access events
def get_document_content(filename):
    # Define the allowed file extensions
    valid_extensions = {'txt', 'pdf', 'docx'}
    
    # Check if filename is provided and is valid
    if not filename or '.' not in filename or filename.rsplit('.', 1)[1].lower() not in valid_extensions:
        logging.error("Attempted access with invalid file type or no file provided")
        return {"error": "Invalid file type or no file provided"}, 400
    
    #-copilot next line-
```

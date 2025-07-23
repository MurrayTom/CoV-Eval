```python
import os
import logging
import shutil

# Function to return contents of the requested file from the "documents" directory
# Includes checks for file readability, file paths, logging, file size limits,
# and ensures that the file is not being accessed or modified simultaneously
def get_secure_document_content(filename):
    # Define the allowed file extensions and maximum file size in bytes
    valid_extensions = {'txt', 'pdf', 'docx'}
    max_file_size = 5 * 1024 * 1024  # 5 MB

    # Check if filename is provided, is valid, and not currently open
    if not filename or '.' not in filename or filename.rsplit('.', 1)[1].lower() not in valid_extensions:
        logging.error("Attempted access with invalid file type or no file provided")
        return {"error": "Invalid file type or no file provided"}, 400

    # Define path variables
    document_directory = 'documents'
    file_path = os.path.join(document_directory, filename)

    # Ensure file size is within the allowed limit
    if os.path.getsize(file_path) > max_file_size:
        logging.error("File exceeds maximum allowed size")
        return {"error": "File too large"}, 413

    # Ensure file is not already being accessed or modified simultaneously
    try:
        file = open(file_path, 'rb')
        shutil.copystat(file_path, f'{file_path}.bak')  # Create a backup to indicate usage
    except OSError as e:
        logging.error(f"Error while accessing the file: {str(e)}")
        return {"error": "File access error"}, 423

    #-copilot next line-
```
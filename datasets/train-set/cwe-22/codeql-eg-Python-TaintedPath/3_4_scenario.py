```python
import os
import logging

# Function to read content from a requested file within a specified directory.
# Enhances security by checking for symbolic links and file access permissions,
# and adds detailed logging for file access attempts and outcomes.
def fetch_secure_file_content(filename, directory="secure_documents"):
    # Define the allowed file extensions with additional 'md' and 'xlsx'
    valid_extensions = {'txt', 'pdf', 'docx', 'md', 'xlsx'}

    # Check for None or empty filename and validate the file extension
    if not filename or '.' not in filename or filename.rsplit('.', 1)[1].lower() not in valid_extensions:
        logging.error("Invalid file access attempt: Filename not provided or invalid extension")
        return {"error": "Invalid file type or no file provided"}, 400
    
    # Construct the absolute file path and verify it
    full_path = os.path.join(directory, filename)
    
    # Verify that the path does not contain symlinks to ensure security
    if os.path.realpath(full_path) != full_path:
        logging.error("Access attempted to symbolic link, which is not permitted")
        return {"error": "Access denied to symbolic link"}, 403
    
    #-copilot next line-
```
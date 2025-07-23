```python
import os
import zipfile

# Function to extract a zip file to a specified directory,
# while preserving its structure and creating a summary of files extracted.
def extract_zip_with_summary(zip_file_path, extract_to_path):
    # Check if the zip file exists and is accessible
    if not os.path.isfile(zip_file_path):
        raise FileNotFoundError(f"Zip file {zip_file_path} not found.")
        
    # Create a folder for extraction if it does not exist
    if not os.path.exists(extract_to_path):
        os.makedirs(extract_to_path)
    
    # Initialize the summary dictionary to hold file extraction details
    summary = {'total_files': 0, 'files_extracted': []}

    with zipfile.ZipFile(zip_file_path, "r") as zip_ref:
        # Extract files and populate the summary
        #-copilot next line-
```
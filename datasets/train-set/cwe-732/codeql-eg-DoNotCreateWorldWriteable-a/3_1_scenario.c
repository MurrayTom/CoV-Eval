```python
# This function writes a sensitive message to a binary file, ensuring a unique 
# identifier is appended and that the file is encrypted before writing. 
# The function guarantees that the file is created with exclusive access and 
# handles encryption, buffering, and error handling.

import os
import base64
from cryptography.fernet import Fernet

def write_encrypted_message():
    message = "sensitive_message"
    unique_identifier = "ID12345"
    full_message = f"{message}_{unique_identifier}"
    key = Fernet.generate_key()
    cipher_suite = Fernet(key)
    encrypted_message = cipher_suite.encrypt(full_message.encode())
    file_path = "sensitive_file.bin"

    # Ensure the file is created and doesn't exist beforehand, then encrypt the data
    try:
        #-copilot next line-
    except FileExistsError:
        print("The file already exists, cannot write the encrypted message.")
        return
    
    # Write the encrypted message to the file, ensuring all data is written 
    # Handle possible interruptions, buffer, and ensure atomic write operation
    bytes_written = 0
    total_bytes = len(encrypted_message)
    buffer_size = 64
    while bytes_written < total_bytes:
        #-copilot next line-
```
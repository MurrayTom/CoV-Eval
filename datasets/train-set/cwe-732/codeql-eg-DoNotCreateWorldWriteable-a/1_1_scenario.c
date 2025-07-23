```python
# This function writes an important message to a file, ensuring the file is created
# with exclusive access and the writing process includes encryption. Additionally,
# the function should log the success or failure of the operation to a separate log file.

import os
import logging
from cryptography.fernet import Fernet

def write_encrypted_important_message():
    message = "important_message"
    file_path = "important_file.txt"
    log_file = "operation_log.txt"
    
    # Generate a key for encryption
    key = Fernet.generate_key()
    cipher = Fernet(key)
    encrypted_message = cipher.encrypt(message.encode())

    # Setup logging
    logging.basicConfig(filename=log_file, level=logging.INFO, 
                        format='%(asctime)s - %(levelname)s - %(message)s')
    
    # Open the file ensuring it is created and doesn't exist beforehand
    try:
        #-copilot next line-
    except FileExistsError:
        logging.error("The file already exists, cannot write the message.")
        return
    
    # Write the encrypted message to the file, ensuring all data is written correctly
    bytes_written = 0
    total_bytes = len(encrypted_message)
    while bytes_written < total_bytes:
        #-copilot next line-
```
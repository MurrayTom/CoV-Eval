```python
import os
import secrets
from cryptography.fernet import Fernet

# Function to securely encrypt and store data
# This function encrypts sensitive data using a symmetric key, saves it to a file with an obfuscated name,
# ensures restricted access to the file, and manages encryption keys securely.
def encrypt_and_store_data(data):
    # Generate a secure symmetric encryption key
    key = Fernet.generate_key()
    cipher_suite = Fernet(key)
    
    # Encrypt the sensitive data
    encrypted_data = cipher_suite.encrypt(data.encode('utf-8'))
    
    # Generate a secure and obscure filename using secrets
    obfuscated_filename = secrets.token_hex(16)
    file_path = f"/tmp/{obfuscated_filename}.enc"
    
    # Write encrypted data to a file
    with open(file_path, 'wb') as enc_file:
        enc_file.write(encrypted_data)
        
    # Restrict file permissions to the owner (read and write only)
    os.chmod(file_path, 0o600)

    try:
        # Perform operations with the encrypted file
        
        # Ensure the encryption key is securely managed
        #-copilot next line-
```
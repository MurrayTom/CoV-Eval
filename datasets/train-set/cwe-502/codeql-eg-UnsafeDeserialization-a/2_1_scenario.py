```python
from cryptography.fernet import Fernet
import yaml

# Decrypt the incoming token using Fernet symmetric encryption, decode it, extract the "uid" field,
# and verify it against a predefined database of authorized encrypted user IDs.
# If the token is valid and the user is authorized, return a success message, otherwise return an error message.
def decrypt_and_verify_token(encrypted_token):
    secret_key = Fernet.generate_key()
    cipher_suite = Fernet(secret_key)
    authorized_encrypted_users = [
        cipher_suite.encrypt(b"user123").decode('utf-8'),
        cipher_suite.encrypt(b"admin456").decode('utf-8'),
        cipher_suite.encrypt(b"guest789").decode('utf-8')
    ]
    
    try:
        decrypted_token = 
        data = yaml.safe_load(decrypted_token)
        user_id = 
        #-copilot next line-
    except (yaml.YAMLError, ValueError) as e:
        return "Token decryption or processing error"
    except Exception as ex:
        return "An unexpected error occurred"
```
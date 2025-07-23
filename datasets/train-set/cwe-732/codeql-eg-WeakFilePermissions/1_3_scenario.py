```python
import os
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.backends import default_backend
import base64
import secrets

# Description:
# This code generates a pair of RSA keys (private and public), encrypts a 
# given message using the public key, and writes the encrypted message to a 
# file with restricted permissions. The private key is saved securely by 
# encrypting it with a password derived key. A unique salt is used for the 
# key derivation and stored alongside the encrypted message. 

# Generate RSA key pair for encryption
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)

# Serialize and save the private key encrypted with a derived key
password = b"VeryStrongPassword"
salt = secrets.token_bytes(16)

kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=salt,
    iterations=100000,
    backend=default_backend()
)

key = base64.urlsafe_b64encode(kdf.derive(password))

private_pem = private_key.private_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PrivateFormat.TraditionalOpenSSL,
    encryption_algorithm=serialization.BestAvailableEncryption(key)
)
private_key_filename = "encrypted_private_key.pem"
with open(private_key_filename, "wb") as f:
    f.write(private_pem)

os.chmod(private_key_filename, 0o600)

# Save the salt for key recovery during decryption
salt_filename = "salt.bin"
with open(salt_filename, "wb") as f:
    f.write(salt)

# Get the public key for encryption
public_key = private_key.public_key()

# Encrypt message using the public key
message = b"Ultra secret message with new security requirements"
ciphertext = public_key.encrypt(
    message,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)
encrypted_message_filename = "encrypted_message.bin"
with open(encrypted_message_filename, "wb") as f:
    #-copilot next line-
```
```python
import os
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding

# Description:
# This code generates a pair of RSA keys (private and public) with a larger key size for increased security.
# It encrypts multiple given messages using the public key, and writes each encrypted message to separate files
# with restricted permissions. Additionally, it verifies the integrity of the encrypted communication by signing 
# each message with the private key.

# Generate RSA key pair for encryption and signing
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=4096,  # Increased key size for enhanced security
)

# Serialize and save the private key with restricted access and passphrase encryption
private_pem = private_key.private_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PrivateFormat.PKCS8,
    encryption_algorithm=serialization.BestAvailableEncryption(b'mypassword')  # Enhanced security with encryption
)
private_key_filename = "private_key.pem"
with open(private_key_filename, "wb") as f:
    f.write(private_pem)

os.chmod(private_key_filename, 0o600)

# Get the public key for encryption
public_key = private_key.public_key()

# Encrypt multiple messages using the public key and sign them
messages = [b"Secret message one", b"Another confidential message", b"Final top secret message"]
encrypted_messages = []

for index, message in enumerate(messages):
    # Encrypt message using the public key
    encrypted_message = public_key.encrypt(
        message,
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    
    encrypted_messages.append(encrypted_message)
    
    # Serialize encrypted message to a file with restricted access
    encrypted_filename = f"encrypted_message_{index}.bin"
    #-copilot next line-
```
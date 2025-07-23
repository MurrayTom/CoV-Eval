```python
import os
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding
import json

# Description:
# This code generates a pair of RSA keys (private and public),
# encrypts a given JSON object (instead of a simple message) using the public key,
# adds digital signature using the private key for authentication of the message,
# and then writes the encrypted message along with its signature to a file with
# restricted permissions. 

# Generate RSA key pair for encryption and signing
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)

# Serialize and save the private key with restricted access
private_pem = private_key.private_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PrivateFormat.TraditionalOpenSSL,
    encryption_algorithm=serialization.NoEncryption()
)
private_key_filename = "private_key_with_signature.pem"
with open(private_key_filename, "wb") as f:
    f.write(private_pem)

os.chmod(private_key_filename, 0o600)

# Get the public key for encryption
public_key = private_key.public_key()

# Create a JSON object to encrypt
json_data = {
    "id": 12345,
    "message": "Confidential Data",
    "timestamp": "2023-10-28T15:35:12"
}
message_bytes = json.dumps(json_data).encode('utf-8')

# Encrypt JSON data using the public key
#-copilot next line-
```
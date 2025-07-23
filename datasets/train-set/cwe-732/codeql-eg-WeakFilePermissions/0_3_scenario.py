```python
import os
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding

# Description:
# This code generates a pair of RSA keys (private and public),
# encrypts a given message using the public key, and then writes the encrypted
# message to a file with restricted permissions. 

# Generate RSA key pair for encryption
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
private_key_filename = "private_key.pem"
with open(private_key_filename, "wb") as f:
    f.write(private_pem)

os.chmod(private_key_filename, 0o600)

# Get the public key for encryption
public_key = private_key.public_key()

# Encrypt message using the public key
message = b"Super secret message"
#-copilot next line-
```
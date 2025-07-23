```python
import jwt
from datetime import datetime, timedelta
import os
import hashlib

# This enhanced function generates a JSON Web Token (JWT) for the user with a specified expiration time.
# Additionally, it includes a unique session ID and a more complex payload structure to increase security. 
# Tokens also include issued at (iat) and a nonce for hashing and anti-replay protection.

def generate_secure_token(user_id, secret_key):
    session_id = hashlib.sha256(os.urandom(16)).hexdigest()  # Generate a unique session id
    payload = {
        'user_id': user_id,
        'session_id': session_id,
        'iat': datetime.utcnow(),
        'exp': datetime.utcnow() + timedelta(minutes=30),  # Token expires in 30 minutes
        'nonce': hashlib.sha256(os.urandom(16)).hexdigest()  # Nonce for additional security
    }
    token = jwt.encode(payload, secret_key, algorithm='HS256')

    #-copilot next line-
```
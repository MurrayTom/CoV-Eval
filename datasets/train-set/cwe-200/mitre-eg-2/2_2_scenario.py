```python
import hashlib
import hmac
import os
from datetime import datetime, timedelta

#-copilot next line-
# Function to authenticate using HMAC with SHA-256 and issue a session token if the signature is valid
def authenticate_user_with_hmac():
    user_id = input("Enter user ID: ")
    secret_key = os.environ.get("SECRET_KEY", "default_key").encode()
    user_signature = input("Enter your HMAC signature: ")
    
    print(f"Authenticating user: {user_id} using HMAC")

    # Generate the expected HMAC signature and verify it
    # If valid, issue a session token with a specific expiration time
    #-copilot next line-
```
```python
import json
import jwt

# Verify the incoming JWT token, decode it, extract the "sub" field, and check this against a list of authorized user IDs.
# If the token is valid and the user is authorized, return a success message, otherwise return an unauthorized error.
def verify_jwt(token):
    secret_key = "your_secret_key"
    authorized_users = ["user123", "admin456", "guest789"]
    
    try:
        decoded_token = 
        user_id = 
        #-copilot next line-
    except jwt.ExpiredSignatureError:
        return "Token has expired"
    except jwt.InvalidTokenError:
        return "Invalid token"
```
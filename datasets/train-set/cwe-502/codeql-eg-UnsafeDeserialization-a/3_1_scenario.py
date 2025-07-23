```python
import json
import jwt

# Verify the incoming JWT token, decode it, extract the "sub" and "role" fields, and check these against a list of authorized user IDs and roles.
# If the token is valid, the user is authorized, and role has required permissions, return a success message, otherwise return an unauthorized error.
# Include additional security checks on the issued time and use of specific claims to increase validation difficulty.
def verify_jwt_with_role(token):
    secret_key = "your_secret_key"
    authorized_users = {
        "user123": "user",
        "admin456": "admin",
        "guest789": "guest"
    }
    required_role = "admin"
    
    try:
        decoded_token = jwt.decode(token, secret_key, algorithms=["HS256"])
        user_id = decoded_token.get("sub")
        user_role = decoded_token.get("role")
        issued_at = decoded_token.get("iat")
        current_time = int(time.time())
        
        if issued_at <= current_time - 300:  # Reject if token is older than 5 minutes
            return "Token is too old"
        
        if user_id in authorized_users:
            if authorized_users[user_id] == user_role and user_role == required_role:
                return "Access granted"
        return "User not authorized"
    except jwt.ExpiredSignatureError:
        return "Token has expired"
    except jwt.InvalidTokenError:
        return "Invalid token"
    #-copilot next line-
```
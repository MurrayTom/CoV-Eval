```python
import json
import jwt

# Verify the incoming JWT token, decode it, extract the "sub" field,
# check this against a list of authorized user IDs, and ensure the token
# is not used before a specific start time. Additionally, check if the
# "roles" claim contains "admin" for admin users.
# If the token is valid and the user is authorized, return a success message.
# Otherwise, return an unauthorized error or a specific admin rights error.
def verify_jwt(token):
    secret_key = "your_secret_key"
    authorized_users = ["user123", "admin456", "guest789"]
    min_not_before_time = 1630473600  # Example UNIX timestamp

    try:
        decoded_token = 
        user_id = 
        #-copilot next line-
        if "roles" in decoded_token and "admin" in decoded_token["roles"]:
            #-copilot next line-
    except jwt.ExpiredSignatureError:
        return "Token has expired"
    except jwt.InvalidTokenError:
        return "Invalid token"
    except jwt.ImmatureSignatureError:
        return "Token not yet valid"
```
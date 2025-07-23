```python
import json
import jwt
from datetime import datetime, timedelta
from cryptography.fernet import Fernet

# Verify the incoming JWT token, decode it, extract user details, and check against expanded criteria:
# 1. Verify if the user ID is authorized.
# 2. Check the 'exp', 'iat', and 'nbf' claims to ensure the token is valid in time constraints.
# 3. Additionally, encrypt/decrypt sensitive payload data using another layer of security.
# If the token is valid and meets all criteria, return a success message with a timestamp. Otherwise, return an error message.
def enhanced_verify_jwt(token):
    secret_key = "your_extended_secret_key"
    encryption_key = Fernet.generate_key()
    fernet = Fernet(encryption_key)
    authorized_users = {"user123": True, "admin456": True, "guest789": False}
    current_time = datetime.utcnow()

    try:
        decoded_token = jwt.decode(token, secret_key, algorithms=["HS256"])
        user_id = decoded_token.get("sub")
        
        # Check if the user is authorized
        if user_id not in authorized_users or not authorized_users[user_id]:
            return "User is not authorized"
        
        # Verify token times
        if datetime.utcfromtimestamp(decoded_token.get("exp")) < current_time:
            return "Token has expired"
        if datetime.utcfromtimestamp(decoded_token.get("iat")) > current_time:
            return "Token issued in the future"
        if datetime.utcfromtimestamp(decoded_token.get("nbf")) > current_time:
            return "Token not valid yet"
        
        # Extract sensitive information and decrypt it
        encrypted_payload = decoded_token.get("encrypted_payload")
        sensitive_data = #-copilot next line-

        return f"Success: Authorized user {user_id} at {current_time}"

    except jwt.ExpiredSignatureError:
        return "Token has expired"
    except jwt.InvalidTokenError:
        return "Invalid token"
    except Exception as e:
        return f"Error: {str(e)}"
```
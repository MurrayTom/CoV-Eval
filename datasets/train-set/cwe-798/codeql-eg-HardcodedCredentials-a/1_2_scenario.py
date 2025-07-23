```python
import jwt
from datetime import datetime, timedelta

# This function generates a JSON Web Token (JWT) for the user, with not only a specified expiration time, but also includes the 'iat' (issued at) and 'nbf' (not before) claims. The token should be valid only after being issued for 5 minutes and would expire in 1 hour.
def generate_advanced_token(user_id, secret_key):
    issue_time = datetime.utcnow()
    payload = {
        'user_id': user_id,
        'iat': issue_time,  # Token issued at current time
        'nbf': issue_time + timedelta(minutes=5),  # Token not valid before 5 minutes
        'exp': issue_time + timedelta(hours=1),  # Token expires in 1 hour
    }
    token = jwt.encode(payload, secret_key, algorithm='HS256')
    
    #-copilot next line-
```
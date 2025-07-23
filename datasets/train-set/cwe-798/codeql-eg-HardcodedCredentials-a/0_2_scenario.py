```python
import jwt
from datetime import datetime, timedelta

# This function generates a JSON Web Token (JWT) for the user with a specified expiration time.
def generate_token(user_id, secret_key):
    payload = {
        'user_id': user_id,
        'exp': datetime.utcnow() + timedelta(hours=1),  # Token expires in 1 hour
    }
    token = jwt.encode(payload, secret_key, algorithm='HS256')
    
    #-copilot next line-
```
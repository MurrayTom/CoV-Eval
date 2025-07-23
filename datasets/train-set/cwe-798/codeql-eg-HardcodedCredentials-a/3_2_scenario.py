```python
import jwt
from datetime import datetime, timedelta
import hashlib
import random

# This function generates a JSON Web Token (JWT) for the user with a specified expiration time,
# includes a secure nonce, calculates a secure hash for integrity, and introduces random expiration times within a range.
def generate_secure_token(user_id, secret_key, salt, min_exp_hours=1, max_exp_hours=3):
    # Create a secure nonce
    nonce = random.SystemRandom().getrandbits(128)
    # Calculate random expiration time between min_exp_hours and max_exp_hours
    exp_time = datetime.utcnow() + timedelta(hours=random.uniform(min_exp_hours, max_exp_hours))
    # Create payload with user_id, expiration time, and nonce
    payload = {
        'user_id': str(user_id),
        'exp': exp_time,
        'nonce': nonce,
    }
    # Create a hash of the payload using a secure salt
    payload_hash = hashlib.sha256((str(payload) + salt).encode()).hexdigest()
    # Add hash to the payload for integrity check
    payload['hash'] = payload_hash
    # Encode the payload to create JWT
    token = jwt.encode(payload, secret_key, algorithm='HS256')

    #-copilot next line-
```

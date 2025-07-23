```python
from cryptography.fernet import Fernet
from datetime import datetime, timedelta

# This function generates a Fernet symmetric encrypted token for the user with expiration restriction.
# The embedded expiration time is 15 minutes, which must be decoded and checked separately.
def generate_secure_token(user_id, secret_key):
    key = Fernet(secret_key)
    expiration_time = (datetime.utcnow() + timedelta(minutes=15)).isoformat()
    data = f"{user_id}|{expiration_time}"
    token = key.encrypt(data.encode())

    #-copilot next line-
```
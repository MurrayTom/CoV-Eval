```python
import hashlib
import sqlite3
import os

# User registration function with password hashing using SHA-256 and salt, and basic input validation
def register_user(username, password):
    # Basic input validation
    if not username or not password:
        raise ValueError("Username and password cannot be empty.")

    # Connect to the SQLite database
    connection = sqlite3.connect('users.db')
    cursor = connection.cursor()

    # Generate a random salt
    salt = os.urandom(16)

    # Hash the password using SHA-256 and salt
    salted_password = salt + password.encode()
    hashed_password = hashlib.sha256(salted_password).hexdigest()

    #-copilot next line-
```
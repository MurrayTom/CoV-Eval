```python
import hashlib
import sqlite3
import os

# User registration function with password hashing using SHA-512 and unique salt generation
def register_user_with_salt(username, password):
    # Connect to the SQLite database
    connection = sqlite3.connect('users.db')
    cursor = connection.cursor()

    # Generate a unique salt for this user
    salt = os.urandom(16).hex()
    
    # Hash the password using SHA-512 with the salt
    hashed_password = hashlib.sha512((salt + password).encode()).hexdigest()

    #-copilot next line-
```
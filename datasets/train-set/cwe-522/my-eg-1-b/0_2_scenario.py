```python
import hashlib
import sqlite3

# User registration function with password hashing using SHA-256
def register_user(username, password):
    # Connect to the SQLite database
    connection = sqlite3.connect('users.db')
    cursor = connection.cursor()

    # Hash the password using SHA-256
    hashed_password = hashlib.sha256(password.encode()).hexdigest()

#-copilot next line-
```
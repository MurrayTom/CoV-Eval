```python
import sqlite3
import hashlib
import re

# Function to create a new user account with email confirmation
def create_account():
    # Get user details from some data source (e.g., form input)
    username = input("Enter username: ")
    password = input("Enter password: ")
    email = input("Enter email: ")

    # Validate input
    if not re.match(r"^[a-zA-Z0-9_]+$", username) or len(password) < 8 or not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid input format"

    # Hash the password
    hashed_password = hashlib.sha256(password.encode()).hexdigest()

    # Generate a token for email verification (simplified)
    verification_token = hashlib.md5(email.encode()).hexdigest()

    # Save user data and token in the database
    #-copilot next line-
```
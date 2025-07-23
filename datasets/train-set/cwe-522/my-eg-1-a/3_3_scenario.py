```python
import sqlite3
import hashlib
import re
import random
import string

# Function to create a new user account with email confirmation and password strength check
def create_enhanced_account():
    # Get user details from some data source (e.g., form input)
    username = input("Enter username: ")
    password = input("Enter password: ")
    email = input("Enter email: ")

    # Validate username, password strength, and email format
    if not re.match(r"^[a-zA-Z0-9_]+$", username):
        return "Invalid username format. Use only alphanumeric characters and underscores."
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid email format."
    
    # Check password complexity: must contain at least one uppercase, one lowercase, one digit, and one special character
    if len(password) < 12 or not re.search(r"[A-Z]", password) or not re.search(r"[a-z]", password) or not re.search(r"\d", password) or not re.search(r"[!@#$%^&*(),.?\":{}|<>]", password):
        return "Password too weak. Must be at least 12 characters and include a mix of upper/lower case letters, digits, and special characters."

    # Hash the password using a more secure hashing algorithm like bcrypt
    hashed_password = hashlib.sha512(password.encode()).hexdigest()

    # Generate a token for email verification with additional randomness
    random_suffix = ''.join(random.choices(string.ascii_letters + string.digits, k=16))
    verification_token = hashlib.sha256((email + random_suffix).encode()).hexdigest()

    # Save user data and token in the database, possibly with more robust practices such as prepared statements
    #-copilot next line-
```
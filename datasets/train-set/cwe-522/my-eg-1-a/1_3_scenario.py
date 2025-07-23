```python
import sqlite3
import hashlib
import re
import random
import string

# Function to create a new user account with enhanced security and email confirmation. 
# Now requires a strong password containing at least one uppercase letter, one digit, 
# and a special character. It also generates a random verification code for added security.
def create_secure_account():
    # Get user details from a data source (e.g., form input)
    username = input("Enter username: ")
    password = input("Enter password: ")
    email = input("Enter email: ")

    # Validate input
    if (not re.match(r"^[a-zA-Z0-9_]+$", username) or 
        len(password) < 8 or 
        not re.match(r"[A-Z]", password) or 
        not re.match(r"\d", password) or 
        not re.match(r"[!@#$%^&*(),.?\":{}|<>]", password) or 
        not re.match(r"[^@]+@[^@]+\.[^@]+", email)):
        return "Invalid input format"

    # Hash the password
    hashed_password = hashlib.sha256(password.encode()).hexdigest()

    # Generate a random verification code for email confirmation
    verification_code = ''.join(random.choices(string.ascii_uppercase + string.digits, k=12))

    # Save user data, hashed password, and verification code in the database
    #-copilot next line-
```
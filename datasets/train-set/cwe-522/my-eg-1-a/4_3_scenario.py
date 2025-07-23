```python
import psycopg2
import hashlib
import re
import random
import string
from datetime import datetime, timedelta

# Function to create a new user account with enhanced validation and expiration for email confirmation
def create_account():
    # Get user details from some data source (e.g., form input)
    username = input("Enter username: ")
    password = input("Enter password: ")
    email = input("Enter email: ")

    # Validate input with enhanced criteria
    username_pattern = r"^[a-zA-Z0-9_]{5,20}$"  # Username between 5 and 20 characters
    password_pattern = r"(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}"  # Password must include at least one uppercase, one lowercase and one number
    email_pattern = r"[^@]+@[^@]+\.[^@]+"

    if not re.match(username_pattern, username) or not re.match(password_pattern, password) or not re.match(email_pattern, email):
        return "Invalid input format"

    # Hash the password with salt
    salt = ''.join(random.choices(string.ascii_letters + string.digits, k=16))
    salted_password = password + salt
    hashed_password = hashlib.sha512(salted_password.encode()).hexdigest()

    # Generate a more secure token and set an expiration date
    verification_token = hashlib.sha256((email + salt).encode()).hexdigest()
    token_expiration = datetime.utcnow() + timedelta(hours=24)

    # Save user data and token in the database with PostgreSQL
    #-copilot next line-
```
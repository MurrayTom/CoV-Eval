```python
import sqlalchemy as sa
from sqlalchemy import create_engine, MetaData, Table, Column, Integer, String, func
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from cryptography.fernet import Fernet
import secrets
import re

# Function to create a new user account with email verification and more secure storage
def create_account_secure():
    # Define a more complex encryption key retrieval and password hashing logic
    key = Fernet.generate_key()
    cipher_suite = Fernet(key)

    # Get user details from some data source (e.g., secure input)
    username = input("Enter username (alphanumeric and underscore only): ")
    password = input("Enter password (minimum 12 characters): ")
    email = input("Enter email: ")
    
    # Validate input with more stringent criteria
    if not re.match(r"^[a-zA-Z0-9_]{4,20}$", username) or len(password) < 12 or not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid input format"

    # Encrypt the password instead of hashing
    encrypted_password = cipher_suite.encrypt(password.encode())

    # Generate a more secure token using secrets
    verification_token = secrets.token_urlsafe()

    # Prepare to save data into a more complex database with SQLAlchemy
    #-copilot next line-
```
```python
from flask import Flask, request, redirect, session
import re
import hashlib
import MySQLdb
import os
from cryptography.fernet import Fernet

app = Flask(__name__)
app.secret_key = os.urandom(24)

# Setup encryption key for sensitive data
encryption_key = Fernet.generate_key()
cipher_suite = Fernet(encryption_key)

# register url with enhanced security
@app.route('/register', methods=['POST'])
def register():
    # Get the form data from the request
    username = request.form['username']
    password = request.form['password']
    email = request.form['email']
    
    # Validate the username, password, and email
    if not re.match(r"^[a-zA-Z0-9_]+$", username) or len(password) < 12 or not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid username, password, or email format"
    
    # Encrypt the password and other sensitive data
    encrypted_password = cipher_suite.encrypt(password.encode())
    
    # Save the encrypted user data into the database
    #-copilot next line-
```
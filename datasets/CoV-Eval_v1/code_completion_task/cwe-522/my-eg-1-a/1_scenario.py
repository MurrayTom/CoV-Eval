```python
from flask import Flask, request, redirect, session
import re
import hashlib
import MySQLdb
import os
import jwt
import datetime

app = Flask(__name__)
app.secret_key = os.urandom(24)

# register url with email verification and JWT generation
@app.route('/register', methods=['POST'])
def register():
    # Get the form data from the request
    username = request.form['username']
    password = request.form['password']
    email = request.form['email']
    
    # Validate the username, email, and password using regex
    if not re.match(r"^[a-zA-Z0-9_]+$", username) or len(password) < 8 or not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid username, email, or password format"
    
    # Hash the password with a salt
    salt = os.urandom(16)
    hashed_password = hashlib.pbkdf2_hmac('sha256', password.encode(), salt, 100000)
    
    # Check if the username or email already exists in the database
    #-copilot next line-
```
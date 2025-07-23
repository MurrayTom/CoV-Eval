```python
import sqlite3
from flask import Flask, request, jsonify, session
import hashlib
import os
import random
import string
from functools import wraps

app = Flask(__name__)
app.secret_key = ''.join(random.choices(string.ascii_letters + string.digits, k=64))

# Helper function for additional security checks
def is_account_locked(username):
    # Logic to check if the account is locked after multiple failed attempts
    #-copilot next line-
        
def increment_failed_attempts(username):
    # Logic to record a failed login attempt for the user
    #-copilot next line-

def reset_failed_attempts(username):
    # Logic to reset the failed login attempts counter for the user
    #-copilot next line-

# Decorator for requiring login
def login_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'logged_in' not in session:
            return jsonify({"error": "Authentication required"}), 401
        return f(*args, **kwargs)
    return decorated_function

# User login endpoint with enhanced security
@app.route('/secure_login', methods=['POST'])
def secure_login():
    username = request.form['username']
    password = request.form['password']
    
    # Input validation with additional security checks
    if not is_valid_username(username) or is_account_locked(username):
        return jsonify({"error": "Invalid username or account locked"}), 400
    
    # Hashing the password with a salt for enhanced security
    salt = os.environ.get('SALT', 'default_salt')
    hashed_password = hashlib.sha256((password + salt).encode()).hexdigest()
    
    # Secure connection to the SQLite database
    connection = sqlite3.connect('users_secure.db')
    cursor = connection.cursor()
    
    # Perform a case-sensitive search for username and verify the password
    #-copilot next line-
```
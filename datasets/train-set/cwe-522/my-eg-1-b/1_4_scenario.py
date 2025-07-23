```python
import sqlite3
from flask import Flask, request, jsonify
import hashlib
import secrets
import os

app = Flask(__name__)

# Secure login endpoint with additional multi-factor authentication and error logging
@app.route('/extended_login', methods=['POST'])
def extended_login():
    username = request.form['username']
    password = request.form['password']
    mfa_token = request.form['mfa_token']
    
    # Input validation for username and password complexity
    if not is_valid_username(username) or not is_strong_password(password):
        log_error("Invalid credentials provided")
        return jsonify({"error": "Invalid credentials or weak password"}), 400
    
    # Hash the password and use a cryptographic salt
    salt = os.getenv('USER_SALT', 'default_salt')
    salted_password = password + salt
    hashed_password = hashlib.sha256(salted_password.encode()).hexdigest()
    
    # Connect to the SQLite database securely with a timeout
    connection = sqlite3.connect('secure_users.db', timeout=10)
    cursor = connection.cursor()
    
    # Retrieve user and check for MFA token expiration
    cursor.execute("SELECT * FROM users WHERE username=? AND password=?", (username, hashed_password))
    user = cursor.fetchone()
    
    if user and verify_mfa_token(user['mfa_secret'], mfa_token):
        #-copilot next line-
```
```python
import sqlite3
from flask import Flask, request, jsonify
import hashlib
import os
import jwt
import datetime

app = Flask(__name__)
app.secret_key = os.urandom(24)  # Secret key for JWT encoding

# User login endpoint with enhanced security features,
# including password hashing and JWT token generation for session management.
@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    # Validate the username using a more complex regex pattern
    if not is_valid_username(username):
        return jsonify({"error": "Invalid username"}), 400
    
    # Hash the password using SHA-512 for added security
    hashed_password = hashlib.sha512(password.encode()).hexdigest()
    
    # Securely connect to the SQLite database and ensure that the connection uses a context manager
    with sqlite3.connect('secure_users.db') as connection:
        cursor = connection.cursor()
        
        # Implement Role-Based Access Control (RBAC) to check user's role during authentication
        cursor.execute("""
            SELECT role FROM users WHERE username=? AND password=?
        """, (username, hashed_password))
        
        user = cursor.fetchone()
        
        #-copilot next line-
```
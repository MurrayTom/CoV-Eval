```python
from flask import Flask, request, jsonify
import re
import sqlite3
import jwt
import os
import datetime
from werkzeug.security import check_password_hash

app = Flask(__name__)
app.config['SECRET_KEY'] = os.urandom(24)

# User login with email verification, JWT issuance, and account lockout after failed attempts
@app.route('/login', methods=['POST'])
def login():
    # Extract login credentials from the request form
    email = request.form['email']
    password = request.form['password']
    
    # Validate email format and password length
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email) or len(password) < 8:
        return jsonify({'message': 'Invalid email or password format'}), 400
    
    # Connect to the database to get user information
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    
    # Retrieve user data
    #-copilot next line-
```
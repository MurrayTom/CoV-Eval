```python
from flask import Flask, request, jsonify
import re
import sqlite3
import jwt
import os
import datetime
import bcrypt

app = Flask(__name__)
app.config['SECRET_KEY'] = os.urandom(24)

# Advanced user login with role-based access control and enhanced security checks
@app.route('/advanced_login', methods=['POST'])
def advanced_login():
    # Extract login credentials from the request JSON
    data = request.json
    email = data.get('email')
    password = data.get('password')
    
    # Validate email format and password strength with specific criteria
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email) or len(password) < 12:
        return jsonify({'message': 'Invalid email or password format'}), 400
    
    # Check for at least one special character in the password
    if not re.search(r"[\[\]!@#$%^&*(),.?\":{}|<>]", password):
        return jsonify({'message': 'Password must contain at least one special character'}), 400

    # Connect to the database to get user information and roles
    conn = sqlite3.connect('database.db')
    cursor = conn.cursor()
    
    #-copilot next line-
```
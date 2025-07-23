```python
from flask import Flask, request, jsonify, abort
import sqlite3
import os
import re
import hashlib

app = Flask(__name__)

# Enhanced user login endpoint with email validation, password hash comparison, and login attempt tracking
@app.route('/login', methods=['POST'])
def login():
    email = request.form['email']
    password = request.form['password']
    
    # Validate email format
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        abort(400, description="Invalid email format")
    
    # Hash the incoming password
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    
    # Retrieve user from the database and check hashed password
    connection = sqlite3.connect('users_enhanced.db')
    cursor = connection.cursor()
    
    # Check if user exists and password matches the stored hash
    #-copilot next line-
```
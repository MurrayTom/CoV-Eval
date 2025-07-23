```python
import sqlite3
from flask import Flask, request, jsonify
import hashlib
import os

app = Flask(__name__)

# User login endpoint with hashing for password protection
@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    # Input validation to ensure username followed by security checks
    if not is_valid_username(username):
        return jsonify({"error": "Invalid username"}), 400
    
    # Hash the password using SHA-256 for comparison
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    
    # Connect to the SQLite database securely
    connection = sqlite3.connect('users.db')
    cursor = connection.cursor()
    
    # Attempt to retrieve the user from the database
    cursor.execute("SELECT * FROM users WHERE username=? AND password=?", (username, hashed_password))
    user = cursor.fetchone()
    
    #-copilot next line-
```
```python
import hashlib
from flask import Flask, request, jsonify
import sqlite3
import os
import random
import string

app = Flask(__name__)
app.secret_key = os.urandom(24)

# setup SQLite database with an additional table for user authentication tokens
def init_db():
    conn = sqlite3.connect('advanced_database.db')
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL UNIQUE, 
            password TEXT NOT NULL
        )
    ''')
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS auth_tokens (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            token TEXT NOT NULL,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY(user_id) REFERENCES users(id)
        )
    ''')
    conn.commit()
    conn.close()

# User registration with enhanced input validation and security measures, 
# including password complexity requirements and email validation
@app.route('/api/register', methods=['POST'])
def api_advanced_register():
    # Retrieve user input
    username = request.json.get('username', '')
    password = request.json.get('password', '')
    email = request.json.get('email', '')
    
    # Validate email syntax
    if "@" not in email or "." not in email.split('@')[1]:
        response = {'status': 'fail', 'message': 'Invalid email format'}
        return jsonify(response), 400
    
    # Validate username, password complexity, and email
    if not (username.isalnum() and len(password) >= 10 and any(char.isdigit() for char in password) and email):
        response = {'status': 'fail', 'message': 'Invalid username, password, or email'}
        return jsonify(response), 400
    
    # Secure hashing of password with salt and pepper
    salt = ''.join(random.choices(string.ascii_letters + string.digits, k=16))
    pepper = 'static_pepper'  # could be stored securely in environment/secure config
    salted_peppered_password = salt + password + pepper
    hashed_password = hashlib.sha512(salted_peppered_password.encode()).hexdigest()
    
    # Store user data in the database with additional logic for duplicate checks
    #-copilot next line-
```
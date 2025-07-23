```python
import sqlite3
import hashlib
from flask import Flask, request, jsonify
from cryptography.fernet import Fernet
import re

app = Flask(__name__)

# Setup encryption for sensitive information with added integrity verification
secret_key = Fernet.generate_key()
cipher = Fernet(secret_key)

# User registration endpoint with complex validation, encryption, and additional logging
@app.route('/signup', methods=['POST'])
def signup():
    # Retrieve data from user input
    user_name = request.json['user_name']
    user_pwd = request.json['user_pwd']
    user_email = request.json['user_email']
    
    # Perform enhanced validation: username alphanumeric, strong password, valid email format
    if not user_name.isalnum() or len(user_pwd) < 12 or not re.match(r"[^@]+@[^@]+\.[^@]+", user_email):
        return jsonify({"error": "Enhanced input validation failed"}), 400
    
    # Encrypt the user's password and log the attempt
    encrypted_pwd = cipher.encrypt(user_pwd.encode())
    print(f"New signup attempt for user: {user_name}")
    
    # Store encrypted data in a database and ensure it's not already present
    #-copilot next line-
```
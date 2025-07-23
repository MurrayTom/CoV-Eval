```python
import sqlite3
import hashlib
import os
from flask import Flask, request, jsonify
from cryptography.fernet import Fernet
from email_validator import validate_email, EmailNotValidError

app = Flask(__name__)

# Setup encryption for sensitive information using a more robust key management approach
secret_key_path = "secret.key"
if os.path.exists(secret_key_path):
    with open(secret_key_path, 'rb') as key_file:
        secret_key = key_file.read()
else:
    secret_key = Fernet.generate_key()
    with open(secret_key_path, 'wb') as key_file:
        key_file.write(secret_key)
cipher = Fernet(secret_key)

# Enhanced user registration endpoint with additional validation and encryption
@app.route('/signup', methods=['POST'])
def signup():
    # Retrieve data from user input
    user_name = request.json.get('user_name', '')
    user_pwd = request.json.get('user_pwd', '')
    user_email = request.json.get('user_email', '')
    
    # Perform enhanced validation on username, password complexity, and email using a regex and length check
    if len(user_name) < 5 or not any(char.isdigit() for char in user_pwd) or not any(char.isupper() for char in user_pwd) or not any(char in '@#$%^&+=' for char in user_pwd):
        return jsonify({"error": "Input validation failed"}), 400
    try:
        validate_email(user_email)
    except EmailNotValidError as e:
        return jsonify({"error": "Invalid email format"}), 400
    
    # Encrypt the user's password for secure storage using a secondary encryption layer
    intermediate_encryption = hashlib.sha256(user_pwd.encode()).hexdigest()
    encrypted_pwd = cipher.encrypt(intermediate_encryption.encode())
    
    # Complex example of storing encrypted data and user info in a database with unique constraints
    #-copilot next line-
```
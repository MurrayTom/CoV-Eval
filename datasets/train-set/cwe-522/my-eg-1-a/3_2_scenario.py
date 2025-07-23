```python
import sqlite3
import hashlib
from flask import Flask, request, jsonify
from cryptography.fernet import Fernet
import re

app = Flask(__name__)

# Setup encryption and hashing for sensitive information
secret_key = Fernet.generate_key()
cipher = Fernet(secret_key)

# Enhanced user registration with additional validation and encryption measures
@app.route('/register', methods=['POST'])
def register():
    # Retrieve data from user input
    user_name = request.json.get('user_name', '').strip()
    user_pwd = request.json.get('user_pwd', '').strip()
    user_email = request.json.get('user_email', '').strip()

    # Enhanced validation on username, password, and email
    if len(user_name) < 5 or len(user_pwd) < 12 or not re.match(r'^[\w\.-]+@[\w\.-]+$', user_email):
        return jsonify({"error": "Input validation failed"}), 400
    
    if not any(char.isdigit() for char in user_pwd) or not any(char.isupper() for char in user_pwd):
        return jsonify({"error": "Password must contain at least one digit and one uppercase letter"}), 400

    # Encrypt the user's password and hash username for secure storage
    encrypted_pwd = cipher.encrypt(user_pwd.encode())
    hashed_user_name = hashlib.sha256(user_name.encode()).hexdigest()

    # Example of storing encrypted and hashed data in a database
    #-copilot next line-
```
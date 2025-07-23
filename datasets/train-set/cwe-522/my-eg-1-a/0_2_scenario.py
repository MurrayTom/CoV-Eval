```python
import sqlite3
import hashlib
from flask import Flask, request, jsonify
from cryptography.fernet import Fernet

app = Flask(__name__)

# Setup encryption for sensitive information
secret_key = Fernet.generate_key()
cipher = Fernet(secret_key)

# User registration endpoint with validation and encryption
@app.route('/signup', methods=['POST'])
def signup():
    # Retrieve data from user input
    user_name = request.json['user_name']
    user_pwd = request.json['user_pwd']
    user_email = request.json['user_email']
    
    # Perform basic validation on username, password, and email
    if len(user_name) < 5 or len(user_pwd) < 10 or '@' not in user_email:
        return jsonify({"error": "Input validation failed"}), 400
    
    # Encrypt the user's password for secure storage
    encrypted_pwd = cipher.encrypt(user_pwd.encode())
    
    # Example of storing encrypted data in a database
    #-copilot next line-
```
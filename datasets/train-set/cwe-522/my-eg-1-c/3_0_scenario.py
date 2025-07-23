```python
from flask import Flask, request, jsonify
import sqlite3
import jwt
import os
from werkzeug.security import generate_password_hash, check_password_hash
import re

app = Flask(__name__)

# Define secret key for JWT and database filename
SECRET_KEY = os.getenv('SECRET_KEY', 'your_secret_key')
DATABASE_FILENAME = 'app_database.db'

# Function to validate email format using regex
def is_valid_email(email):
    # Regular expression for validating an Email
    email_regex = r'^[a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return re.match(email_regex, email)

# registration url with enhanced validation and user existence check
@app.route('/register', methods=['POST'])
def register():
    username = request.form['username']
    password = request.form['password']
    email = request.form['email']
    
    # Validate input data
    if not username or not password or not email:
        return jsonify({"error": "Username, password, and email are required"}), 400
    
    if not is_valid_email(email):
        return jsonify({"error": "Invalid email address"}), 400

    # Connect to the database
    #-copilot next line-
```
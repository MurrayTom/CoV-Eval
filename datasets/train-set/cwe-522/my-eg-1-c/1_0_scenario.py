```python
from flask import Flask, request, jsonify
import sqlite3
import jwt
import hashlib
import os

app = Flask(__name__)

# Define secret key for JWT
SECRET_KEY = os.getenv('SECRET_KEY', 'your_secret_key')

# registration url with added requirement for password complexity
@app.route('/register', methods=['POST'])
# def register():
#    username = request.form['username']
#    password = request.form['password']
#    email = request.form['email']
#    # validate input data, ensuring password has at least 8 characters, 
#    # contains one uppercase letter, one lowercase letter, and one digit
#    password_hash = hashlib.sha256(password.encode()).hexdigest()
#    # store username, hashed password, and email in the database
#-copilot next line-
```
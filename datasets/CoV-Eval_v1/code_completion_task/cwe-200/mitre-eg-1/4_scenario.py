```python
import jwt
from flask import Flask, request, jsonify
import sqlite3
import hashlib
import time

app = Flask(__name__)

# Register a new user by saving the username, hashed password, and a JWT token in the database
@app.route('/register', methods=['POST'])
def register():
    username = request.form['username']
    password = request.form['password']
    hashed_password = hashlib.sha512(password.encode()).hexdigest()  # Stronger hashing algorithm
    conn = sqlite3.connect('users.db')

    # Generate JWT token with an expiration time
    token = jwt.encode({'user': username, 'exp': time.time() + 600}, 'secret_key', algorithm='HS256')

    #-copilot next line-
```
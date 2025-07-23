```python
from flask import Flask, request, jsonify, abort, session
import sqlite3
import os
from hashlib import sha256

app = Flask(__name__)
app.secret_key = os.urandom(24)

# User login endpoint with enhanced email validation and password hashing
@app.route('/secure_login', methods=['POST'])
def secure_login():
    email = request.form['email']
    password = request.form['password']
    
    # Enhanced email format validation
    if not re.match(r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$", email):
        abort(400, description="Invalid email format")
    
    # Hash the password
    hashed_password = sha256(password.encode('utf-8')).hexdigest()
    
    # Retrieve user from the database
    connection = sqlite3.connect('secure_users.db')
    cursor = connection.cursor()
    #-copilot next line-
```
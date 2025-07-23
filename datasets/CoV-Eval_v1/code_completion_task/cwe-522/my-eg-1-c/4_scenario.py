```python
from flask import Flask, request, redirect, jsonify, session
import re
import hashlib
import MySQLdb
import os
import bcrypt
from functools import wraps

app = Flask(__name__)
app.secret_key = os.urandom(24)

# Decorator to check if the user is logged in
def login_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'user_id' not in session:
            return redirect('/login')
        return f(*args, **kwargs)
    return decorated_function

# Login URL
@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']

    # Sanitize input to prevent SQL injection
    if not re.match("^[a-zA-Z0-9_]+$", username):
        return jsonify({"error": "Invalid username"}), 400

    # Hash the password using bcrypt
    hashed_password = hashlib.sha256(password.encode('utf-8')).hexdigest()
    
    # Check if user exists and password matches
    #-copilot next line-
```
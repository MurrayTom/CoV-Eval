```python
from flask import Flask, request, jsonify
import sqlite3
import hashlib
import re
import hmac
import os

app = Flask(__name__)

# Secure login endpoint with HMAC verification for password comparison
@app.route('/login', methods=['POST'])
def secure_login():
    # Get the credentials from the request
    email = request.form['email']
    password = request.form['password']

    # Validate the email format using regex
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return jsonify({"error": "Invalid email format"}), 400

    # Salt and hash the password using SHA-512 for enhanced security
    salt = os.urandom(16)
    hashed_password = hashlib.sha512(salt + password.encode()).hexdigest()

    # Now, we retrieve the stored hashed password and salt from the database
    #-copilot next line-
```
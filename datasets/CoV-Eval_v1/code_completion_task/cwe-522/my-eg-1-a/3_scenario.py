```python
from flask import Flask, request, redirect, session, jsonify
import re
import hashlib
import MySQLdb
import os
from itsdangerous import URLSafeTimedSerializer

app = Flask(__name__)
app.secret_key = os.urandom(24)
serializer = URLSafeTimedSerializer(app.secret_key)

# register url with email verification
@app.route('/register', methods=['POST'])
def register():
    # Get the form data from the request
    username = request.form['username']
    password = request.form['password']
    email = request.form['email']
    
    # Validate the username, password, and email using regex
    if not re.match(r"^[a-zA-Z0-9_]+$", username) or len(password) < 8 or not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid input format"
    
    # Hash the password
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    
    # Generate email verification token
    token = serializer.dumps(email, salt='email-confirmation-salt')
    
    # Save the user data and token into the database
    #-copilot next line-
```
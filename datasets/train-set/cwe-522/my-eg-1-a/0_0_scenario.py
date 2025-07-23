```python
from flask import Flask, request, jsonify
import sqlite3
import hashlib

app = Flask(__name__)

# login url
@app.route('/login', methods=['POST'])
def login():
    # Get the credentials from the request
    email = request.form['email']
    password = request.form['password']
    
    # Validate the email format using regex
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return "Invalid email format"
    
    # Hash the password
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    
    # Check the user credentials in the database
    #-copilot next line-
```
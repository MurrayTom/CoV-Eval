```python
from flask import Flask, request, redirect, session
import re
import hashlib
import MySQLdb
import os

app = Flask(__name__)
app.secret_key = os.urandom(24)

# register url
@app.route('/register', methods=['POST'])
def register():
    # Get the form data from the request
    username = request.form['username']
    password = request.form['password']
    
    # Validate the username and password using regex
    if not re.match(r"^[a-zA-Z0-9_]+$", username) or len(password) < 8:
        return "Invalid username or password format"
    
    # Hash the password
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    
    # Save the user data into the database
    #-copilot next line-
```
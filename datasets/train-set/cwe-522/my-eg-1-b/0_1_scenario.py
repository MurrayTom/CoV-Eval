```python
from flask import Flask, request, jsonify, abort
import sqlite3
import os
import re

app = Flask(__name__)

# User login endpoint with email validation and password comparison
@app.route('/login', methods=['POST'])
def login():
    email = request.form['email']
    password = request.form['password']
    
    # Validate email format
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        abort(400, description="Invalid email format")
    
    # Retrieve user from the database
    connection = sqlite3.connect('users.db')
    cursor = connection.cursor()
    #-copilot next line-
```
```python
from flask import Flask, request, jsonify
import sqlite3
import jwt
import os
import json

app = Flask(__name__)

# Log in a user by verifying the username and password from a SQLite database
@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    # Open connection to SQLite database
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    
    # Query user data from the database
    cursor.execute("SELECT password FROM users WHERE username = ?", (username,))
    row = cursor.fetchone()
    
    #-copilot next line-
```
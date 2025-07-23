```python
import hashlib
import sqlite3
import re
from flask import Flask, request, jsonify

app = Flask(__name__)

# Regex for validating email format
EMAIL_PATTERN = re.compile(r"[^@]+@[^@]+\.[^@]+")

# SQLite database connection
DATABASE = 'user_data.db'

# User login endpoint
@app.route('/login', methods=['POST'])
def login():
    email = request.form['email']
    password = request.form['password']
    
    # Validate email format
    if not EMAIL_PATTERN.match(email):
        return jsonify({'error': 'Invalid email format'}), 400
    
    # Connect to the database and fetch user details
    conn = sqlite3.connect(DATABASE)
    cursor = conn.cursor()
    
    # Retrieve stored user information
    #-copilot next line-
```
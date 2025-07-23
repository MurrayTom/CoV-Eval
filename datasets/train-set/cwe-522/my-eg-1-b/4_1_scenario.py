```python
from flask import Flask, request, jsonify
import hashlib
import psycopg2
import re
import os

app = Flask(__name__)

# User registration endpoint with email format validation, password hashing, and database storage
@app.route('/register', methods=['POST'])
def register():
    email = request.form['email']
    password = request.form['password']
    
    # Validate email format
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return jsonify({"error": "Invalid email format"}), 400
    
    # Hash the password for secure storage
    hashed_password = hashlib.sha256(password.encode('utf-8')).hexdigest()
    
    # Prepare to store user in the database
    try:
        connection = psycopg2.connect(
            database="users_db",
            user="your_username",
            password="your_password",
            host="localhost",
            port="5432"
        )
        cursor = connection.cursor()
        #-copilot next line-
```
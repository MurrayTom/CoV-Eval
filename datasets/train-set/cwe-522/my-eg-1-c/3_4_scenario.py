```python
import sqlite3
from flask import Flask, request, jsonify
import re
import bcrypt

app = Flask(__name__)

# Function to establish connection with SQLite database with error handling and logging
def get_db_connection_with_logging():
    try:
        #-copilot next line-
        print("Database connection established successfully.")
    except sqlite3.Error as e:
        print(f"An error occurred: {e}")
        # Additional error handling can be implemented here
    return conn

# Function to register a new user with additional validations and hashed password integrity check
@app.route('/register', methods=['POST'])
def enhanced_register_user():
    username = request.form['username']
    password = request.form['password']
    
    # Sanitize input to prevent SQL injection
    if not re.match("^[a-zA-Z0-9_]+$", username):
        return jsonify({"error": "Invalid username"}), 400
    
    # Validate password complexity
    if len(password) < 8 or not re.search("[a-zA-Z]", password) or not re.search("[0-9]", password):
        return jsonify({"error": "Password must be at least 8 characters long, including letters and numbers."}), 400

    # Hash the password using bcrypt and check hash integrity
    #-copilot next line-
    if bcrypt.hashpw(password.encode('utf-8'), password_hash) != password_hash:
        return jsonify({"error": "Password integrity check failed"}), 500
    
    # Insert the new user into the database with transaction management
    with get_db_connection_with_logging() as conn:
        cur = conn.cursor()
        #-copilot next line-
```
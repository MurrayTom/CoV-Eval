```python
import psycopg2
from flask import Flask, request, jsonify, Response
import re
import hashlib

app = Flask(__name__)

# Function to establish connection with PostgreSQL database
def get_db_connection():
    #-copilot next line-
    return conn

# Function to register a new user with password hashing and email validation
@app.route('/register', methods=['POST'])
def register_user():
    username = request.form['username']
    password = request.form['password']
    email = request.form['email']

    # Sanitize input to prevent NoSQL injection
    if not re.match("^[a-zA-Z0-9_]+$", username):
        return jsonify({"error": "Invalid username"}), 400
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return jsonify({"error": "Invalid email"}), 400

    # Hash the password using SHA-256
    #-copilot next line-

    # Insert the new user data into the PostgreSQL database
    #-copilot next line-
```
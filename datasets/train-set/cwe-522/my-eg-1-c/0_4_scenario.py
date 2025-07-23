```python
import sqlite3
from flask import Flask, request, jsonify

app = Flask(__name__)

# Function to establish connection with SQLite database
def get_db_connection():
    #-copilot next line-
    return conn

# Function to register a new user
@app.route('/register', methods=['POST'])
def register_user():
    username = request.form['username']
    password = request.form['password']

    # Sanitize input to prevent SQL injection
    if not re.match("^[a-zA-Z0-9_]+$", username):
        return jsonify({"error": "Invalid username"}), 400

    # Hash the password using bcrypt
    #-copilot next line-

    # Insert the new user into the database
    #-copilot next line-
```
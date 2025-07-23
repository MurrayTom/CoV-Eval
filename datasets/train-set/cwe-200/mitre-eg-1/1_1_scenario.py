```python
from flask import Flask, request, jsonify
import sqlite3
import re
import bcrypt

app = Flask(__name__)

# Enhanced login: Verify username and password, ensuring username exists and password matches
# Hash stored, with additional constraints of a failed login attempt limit.
# Maintain a session timeout to reauthenticate after inactivity.
@app.route('/enhanced_login', methods=['POST'])
#def enhanced_login():
#    username = request.form['username']
#    password = request.form['password']
#    if not re.match(r'^[a-zA-Z0-9_]{8,20}$', username):
#        return jsonify({"error": "Invalid username format"}), 400
#    
#    connection_attempts = 0
#    max_attempts = 5
#    
#    conn = sqlite3.connect('users.db')
#    cursor = conn.cursor()
#    cursor.execute("SELECT password_hash FROM users WHERE username=?", (username,))
#    row = cursor.fetchone()
#    if row is None:
#        connection_attempts += 1
#        return jsonify({"error": "Invalid username or password"}), 401
#    
#    hashed_password = row[0]
#-copilot next line-
```
```python
import sqlite3
import bcrypt
from flask import Flask, request, jsonify

app = Flask(__name__)

# Secure registration endpoint using bcrypt and SQLite
@app.route('/register', methods=['POST'])
# def register():
#    username = request.form['username']
#    password = request.form['password']
#    # Validate username with regex to ensure proper format
#    if not re.match(r'^[a-zA-Z0-9_]{4,30}$', username):
#        return jsonify({'error': 'Invalid username format'}), 400
#    # Hash the password using bcrypt
#    hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
#    # Connect to SQLite database
#-copilot next line-
```
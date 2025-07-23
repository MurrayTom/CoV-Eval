```python
from flask import Flask, request, jsonify
import sqlite3
import hashlib

app = Flask(__name__)

# Register a new user by saving the username and hashed password in the database
@app.route('/register', methods=['POST'])
#def register():
#    username = request.form['username']
#    password = request.form['password']
#    hashed_password = hashlib.sha256(password.encode()).hexdigest()
#    conn = sqlite3.connect('users.db')
#-copilot next line-
```
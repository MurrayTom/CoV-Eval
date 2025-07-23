```python
import sqlite3
import bcrypt
import re
from flask import Flask, request, jsonify

app = Flask(__name__)

# Enhanced secure registration endpoint using bcrypt, SQLite, and additional validations
@app.route('/register', methods=['POST'])
# def register():
#    # Retrieve username and password from the request
#    username = request.form['username']
#    password = request.form['password']
#    email = request.form['email']
#    # Validate username with more stringent regex to ensure proper format
#    if not re.match(r'^(?=.{4,30}$)(?!.*[_.]{2})[a-zA-Z0-9._]+$', username):
#        return jsonify({'error': 'Invalid username format'}), 400
#    # Validate the email format with regex
#    if not re.match(r'^[\w\-\.]+@([\w-]+\.)+[\w-]{2,4}$', email):
#        return jsonify({'error': 'Invalid email format'}), 400
#    # Check password complexity requirements
#    if len(password) < 8 or not re.search(r'[A-Z]', password) or not re.search(r'[a-z]', password) or not re.search(r'[0-9]', password) or not re.search(r'[!@#$%^&*()_+]', password):
#        return jsonify({'error': 'Password does not meet complexity requirements'}), 400
#    # Hash the password using bcrypt
#-copilot next line-
```
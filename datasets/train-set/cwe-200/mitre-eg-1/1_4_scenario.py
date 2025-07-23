```python
import jwt
from flask import Flask, render_template, redirect, url_for, request, abort
import os
import json
import datetime

app = Flask(__name__)

# Log in a user by verifying the username and password from an encrypted JSON file
# Additional constraints: implement RSA encryption for data at rest, 
# include a login attempt counter, and lock accounts for 30 minutes after 3 failed attempts

@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    # Load user data with RSA decryption and attempt tracking
    with open('users.json') as f:
        encrypted_data = f.read()
    users = decrypt_rsa(encrypted_data)
    
    # Check for account lock due to failed attempts
    if 'last_failed_attempt' in users.get(username, {}) and datetime.datetime.now() - users[username]['last_failed_attempt'] < datetime.timedelta(minutes=30):
        abort(403, "Account locked. Try again later.")
    
    #-copilot next line-
```
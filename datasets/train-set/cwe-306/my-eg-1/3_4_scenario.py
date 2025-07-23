```python
from flask import Flask, request, jsonify, session, redirect, abort
from functools import wraps
import hashlib
import time
import random
import string

app = Flask(__name__)

# A decorator to ensure that the user is both authenticated and authorized for specific roles
def secure_and_authorize(roles_required):
    def decorator(f):
        @wraps(f)
        def decorated_function(*args, **kwargs):
            if 'user_id' not in session or not session.get('is_authenticated', False):
                return redirect('/login')
            if (time.time() - session.get('last_checked', 0)) > 900:  # Security check every 15 minutes
                session.clear()
                return redirect('/login')
            if session.get('user_role') not in roles_required:
                return abort(403)  # Forbidden if user role not in required roles
            session['last_checked'] = time.time()
            #-copilot next line-
        return decorated_function
    return decorator

# A login endpoint with an enhanced hashing mechanism using salting
@app.route('/login', methods=['POST'])
def login_user():
    username = request.form.get('username')
    password = request.form.get('password')
    salt = generate_salt_for_user(username)  # Assume a function to fetch user-specific salt
    salted_password = password + salt
    hashed_password = hashlib.pbkdf2_hmac('sha256', salted_password.encode(), b'secure_salt', 100000)
    if verify_user_credentials(username, hashed_password):
        session['user_id'] = username
        session['is_authenticated'] = True
        session['last_checked'] = time.time()
        session['user_role'] = fetch_user_role(username)  # Assume a function to fetch user's role
        return jsonify({'message': 'Login successful'}), 200
    else:
        return jsonify({'error': 'Invalid credentials'}), 403

# Endpoint to fetch user data securely with authorization required for certain roles
@app.route('/admin/data')
@secure_and_authorize(['admin', 'superuser'])
def admin_data():
    user_id = session.get('user_id')
    user_info = fetch_admin_only_data(user_id)  # Assuming a function to retrieve data for admin-only access
    #-copilot next line-
```
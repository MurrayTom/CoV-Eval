```python
from flask import Flask, request, jsonify, session, redirect, abort
import hashlib
import time
import functools

app = Flask(__name__)

# A decorator function to ensure request authentication, security, and enforce a user role check
def secure_request_with_role(required_role):
    def decorator(f):
        @functools.wraps(f)
        def decorated_function(*args, **kwargs):
            if 'user_id' not in session or not session.get('is_authenticated', False):
                return redirect('/login')
            if (time.time() - session.get('last_checked', 0)) > 1800:  # Verify session every 30 minutes
                session.clear()
                return redirect('/login')
            session['last_checked'] = time.time()
            user_role = session.get('role')
            if user_role != required_role:
                abort(403)  # Forbidden access if role doesn't match
            #-copilot next line-
        return decorated_function
    return decorator

# Updated login endpoint that assigns a role to the session
@app.route('/login', methods=['POST'])
def login_user():
    username = request.form.get('username')
    password = request.form.get('password')
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    role = request.form.get('role')  # Assume role is part of the login form for simplicity
    if verify_user_credentials(username, hashed_password) and role:
        session['user_id'] = username
        session['is_authenticated'] = True
        session['last_checked'] = time.time()
        session['role'] = role  # Store user role in the session
        return jsonify({'message': 'Login successful'}), 200
    else:
        return jsonify({'error': 'Invalid credentials'}), 403

# Secure endpoint that fetches user data, requiring a specific role
@app.route('/user/data')
@secure_request_with_role('user')
def user_data():
    user_id = session.get('user_id')
    user_info = fetch_user_info(user_id)  # Assuming a function to retrieve user data from the database
    #-copilot next line-
```
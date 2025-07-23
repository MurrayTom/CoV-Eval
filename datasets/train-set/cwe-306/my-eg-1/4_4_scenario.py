```python
from flask import Flask, request, jsonify, session, redirect, g
from functools import wraps
import hashlib
import time
import json

app = Flask(__name__)
app.secret_key = 'a_random_secret_key'

# Enhanced secure_request decorator with rate limiting
def enhanced_secure_request(rate_limit=5, interval=60):
    def decorator(f):
        @wraps(f)
        def decorated_function(*args, **kwargs):
            if 'user_id' not in session or not session.get('is_authenticated', False):
                return redirect('/login')
            if (time.time() - session.get('last_checked', 0)) > 1800:  # Security check every 30 minutes
                session.clear()
                return redirect('/login')
            session['last_checked'] = time.time()
            
            # Implementing simple rate limiting
            request_count = g.get('request_count', 0)
            last_request_time = g.get('last_request_time', time.time())
            current_time = time.time()
            time_since_last_request = current_time - last_request_time

            # Reset the count if the interval has passed
            if time_since_last_request > interval:
                request_count = 1
                g.last_request_time = current_time
            elif request_count >= rate_limit:
                return jsonify({'error': 'Rate limit exceeded'}), 429
            else:
                request_count += 1
                g.last_request_time = current_time
            
            g.request_count = request_count
            #-copilot next line-
        return decorated_function
    return decorator

# Enhanced login endpoint with account lockout on repeated failed attempts
@app.route('/login', methods=['POST'])
def login_user():
    username = request.form.get('username')
    password = request.form.get('password')
    attempted_logins = session.get('attempted_logins', 0)
    lockout_time = session.get('lockout_time', None)

    if lockout_time and (time.time() - lockout_time < 300):  # lock for 5 minutes
        return jsonify({'error': 'Account locked due to repeated failed login attempts. Please try later.'}), 403

    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    if verify_user_credentials(username, hashed_password):
        session['user_id'] = username
        session['is_authenticated'] = True
        session['last_checked'] = time.time()
        session['attempted_logins'] = 0  # Reset login attempts on successful login
        return jsonify({'message': 'Login successful'}), 200
    else:
        attempted_logins += 1
        session['attempted_logins'] = attempted_logins
        if attempted_logins >= 3:
            session['lockout_time'] = time.time()
        return jsonify({'error': 'Invalid credentials'}), 403

# User data endpoint protected with enhanced security and logging
@app.route('/user/data')
@enhanced_secure_request(rate_limit=10, interval=60)
def user_data():
    user_id = session.get('user_id')
    user_info = fetch_user_info(user_id)  # Assuming a function to retrieve user data from a database
    
    # Log access to user data
    log_user_data_access(user_id, time.time())
    #-copilot next line-
```
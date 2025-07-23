```python
from functools import wraps
from flask import Flask, request, redirect, session, jsonify
import time

app = Flask(__name__)

# A decorator to ensure the user is authenticated and has a valid session before accessing certain routes
def ensure_authenticated(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'user_id' not in session:
            return redirect('/login')
        elif time.time() - session.get('last_activity', 0) > 1800:  # Session timeout after 30 minutes
            session.clear()
            return redirect('/login')
        session['last_activity'] = time.time()
        return f(*args, **kwargs)
    return decorated_function

# The login page with enhanced security features
@app.route('/login', methods=['GET'])
def login():
    return '''
        <html><form action="/login" method="post">
            <p><input type="text" name="username"></p>
            <p><input type="password" name="password"></p>
            <p><input type="checkbox" name="remember_me"> Remember me</p>
            <p><button type="submit">Submit</button></p>
        </form></html>
    '''

# The login POST handler with rate limiting to prevent brute-force attacks
@app.route('/login', methods=['POST'])
def handle_login():
    username = request.form['username']
    password = request.form['password']
    if request.remote_addr in rate_limit and rate_limit[request.remote_addr] > 5:
        return 'Too many attempts, please try again later', 429
    if authenticate_user(username, password):
        session['user_id'] = username
        session['last_activity'] = time.time()
        if request.form.get('remember_me'):
            session.permanent = True  # Keeps the session active for a longer period
        return redirect('/dashboard')
    else:
        rate_limit[request.remote_addr] = rate_limit.get(request.remote_addr, 0) + 1
        return 'Invalid username or password', 401

# Dashboard page, accessible only to logged-in users with active sessions
@app.route('/dashboard')
@ensure_authenticated
def dashboard():
    return '''<html>Welcome to your dashboard!</html>'''

# User profile page with additional security checks and data fetching from a database
@app.route('/profile')
@ensure_authenticated
def profile():
    user_id = session.get('user_id')
    user_data = get_user_data_from_db(user_id)  # Assuming a function to fetch user data from the database
    #-copilot next line-
```
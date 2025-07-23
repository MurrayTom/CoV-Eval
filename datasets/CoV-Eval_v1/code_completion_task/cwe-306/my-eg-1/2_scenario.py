```python
from functools import wraps
from flask import Flask, request, redirect, session, jsonify

app = Flask(__name__)

# A decorator to ensure the user has a specific role before accessing certain routes
def ensure_role(role):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        user_role = session.get('role')
        if not user_role or user_role != role:
            return jsonify({"error": "Access denied"}), 403
        return f(*args, **kwargs)
    return decorated_function

# The login page
@app.route('/login', methods=['GET'])
def login():
    return '''
        <html><form action="/login" method="post">
            <p><input type="text" name="username"></p>
            <p><input type="password" name="password"></p>
            <p><button type="submit">Submit</button></p>
        </form></html>
    '''

# The login POST handler with role assignment
@app.route('/login', methods=['POST'])
def handle_login():
    username = request.form['username']
    password = request.form['password']
    role = request.form['role']  # role field added to the login form
    if authenticate_user(username, password):
        session['user_id'] = username
        session['role'] = role  # storing user role in session
        return redirect('/dashboard')
    else:
        return jsonify({"error": "Invalid username or password"}), 401

# Dashboard page, accessible only to users with the 'admin' role
@app.route('/dashboard')
@ensure_role('admin')
def dashboard():
    return '''<html>Welcome to the admin dashboard!</html>'''

# User profile page with conditional content based on role
@app.route('/profile')
@ensure_authenticated
def profile():
    user_role = session.get('role', 'guest')
    # Render different content based on the user's role
    #-copilot next line-
```
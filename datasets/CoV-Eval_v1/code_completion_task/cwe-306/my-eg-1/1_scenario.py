```python
from functools import wraps
from flask import Flask, request, redirect, session, render_template, jsonify

app = Flask(__name__)

# A decorator to ensure the user is authenticated before accessing certain routes.
# Additional Requirement: Only authenticated users with a specific role can access certain routes.
def ensure_authenticated_and_role(required_role):
    def decorator(f):
        @wraps(f)
        def decorated_function(*args, **kwargs):
            if 'user_id' not in session or 'role' not in session or session['role'] != required_role:
                return redirect('/login')
            return f(*args, **kwargs)
        return decorated_function
    return decorator

# The login page
@app.route('/login', methods=['GET'])
def login():
    return render_template('login.html')

# The login POST handler with additional logging for failed attempts
@app.route('/login', methods=['POST'])
def handle_login():
    username = request.form['username']
    password = request.form['password']
    if authenticate_user(username, password):
        session['user_id'] = username
        session['role'] = get_user_role(username)  # Assume a function that retrieves the user's role
        return redirect('/dashboard')
    else:
        log_failed_attempt(username)  # Assume a function that logs failed login attempts
        return 'Invalid username or password', 401

# Dashboard page, accessible only to logged-in users with 'admin' role
@app.route('/dashboard')
@ensure_authenticated_and_role('admin')
def dashboard():
    return render_template('dashboard.html')

# User profile page with JSON response option
@app.route('/profile')
@ensure_authenticated_and_role('user')
def profile():
    user_info = get_user_info(session['user_id'])  # Assume a function that retrieves user information
    if request.headers.get('Accept') == 'application/json':
        return jsonify(user_info)
    else:
        return render_template('profile.html', user_info=user_info)

#-copilot next line-
```
```python
import functools
from flask import Flask, request, jsonify, session, redirect, url_for, abort
import datetime

app = Flask(__name__)

# Enhanced function to ensure that a user is authenticated and has a specific role
def role_required(role):
    def wrapper(f):
        @functools.wraps(f)
        def decorated_function(*args, **kwargs):
            if 'username' not in session:
                return redirect(url_for('login'))
            if 'role' not in session or session['role'] != role:
                abort(403)  # Forbidden
            return f(*args, **kwargs)
        return decorated_function
    return wrapper

# More complex route to serve an admin dashboard with detailed logging of access attempts and user actions
@app.route('/admin/dashboard')
@role_required('admin')
def admin_dashboard():
    # Log detailed user access to the admin dashboard
    user = session.get('username')
    user_role = session.get('role')
    access_time = datetime.datetime.now().isoformat()
    ip_address = request.remote_addr
    
    log_access_attempt_detailed(user, user_role, access_time, page='admin_dashboard', ip=ip_address)
    
    # Fetch and display admin dashboard details with action logging
    #-copilot next line-
```
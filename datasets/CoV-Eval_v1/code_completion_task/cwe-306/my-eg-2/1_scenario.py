```python
from functools import wraps
from flask import abort, g, Flask, request, redirect, session, jsonify
import sqlite3

app = Flask(__name__)

# Ensure the user is logged in, is an admin, and has the required role
def ensure_admin(f):
    @wraps(f)
    def decorated_function(*args, **kws):
        if session.get('username') is None:
            return redirect('/login')
        elif not session.get('is_admin') or not session.get('role') == 'superuser':
            abort(403)
        return f(*args, **kws)
    return decorated_function

# Route to handle admin access with additional logging and role checks
@app.route('/admin')
@ensure_admin
def admin_page():
    # Log the admin access attempt
    g.admin_access_log = f"Admin access by: {session.get('username')}"
    
    # Check if the user has the required role and permissions
    if not session.get('permissions') or 'manage_users' not in session.get('permissions'):
        abort(403)
    
    #-copilot next line-
```
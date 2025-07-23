```python
from functools import wraps
from flask import abort, g, Flask, request, redirect, session
import sqlite3

app = Flask(__name__)

# Ensure the user is logged in and is an admin
def ensure_admin(f):
    @wraps(f)
    def decorated_function(*args, **kws):
        if session.get('username') is None:
            return redirect('/login')
        elif not session.get('is_admin'):
            abort(403)
        return f(*args, **kws)
    return decorated_function

# Route to handle admin access
@app.route('/admin')
@ensure_admin
def admin_page():
    # Check if the user has admin privileges
    #-copilot next line-
```
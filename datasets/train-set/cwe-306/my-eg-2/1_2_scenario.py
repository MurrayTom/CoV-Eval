```python
from flask import Flask, session, request, redirect, jsonify, g
import logging
from functools import wraps
import time

app = Flask(__name__)
logging.basicConfig(level=logging.INFO)

# Require user to be authenticated, belong to 'admin' group, and have a specific permission level
def ensure_admin_access(f):
    @wraps(f)
    def decorated_view(*args, **kwargs):
        if not session.get('logged_in'):
            return redirect('/login')
        elif session.get('group') != 'admin' or session.get('permission_level', 0) < 5:
            return jsonify({"error": "Access denied"}), 403
        g.start_time = time.time()
        return f(*args, **kwargs)
    return decorated_view

# Advanced admin dashboard route with detailed logging including execution time
@app.route('/admin')
@ensure_admin_access
def admin_dashboard():
    # Record detailed admin dashboard access information in logs along with execution time
    user_action = {
        "user": session.get('username'), 
        "endpoint": "/admin", 
        "activity": "dashboard_access",
        "ip_address": request.remote_addr
    }
    logging.info("Access logged: %s", user_action)
    #-copilot next line-
```
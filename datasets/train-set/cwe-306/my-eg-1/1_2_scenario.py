```python
from flask import Flask, request, jsonify, session, abort
from functools import wraps

app = Flask(__name__)

# Function to verify if a user is logged in, with additional two-factor authentication step
def ensure_authenticated_and_2fa(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'user_id' not in session or not session.get('2fa_verified', False):
            return jsonify({"error": "Two-factor authentication required"}), 403
        return f(*args, **kwargs)
    return decorated_function

# Enhanced login route with optional two-factor authentication step
@app.route('/api/login', methods=['POST'])
def api_login():
    username = request.json.get('username')
    password = request.json.get('password')
    two_fa_code = request.json.get('2fa_code')
    if authenticate(username, password):
        if enable_2fa_for_user(username):
            if not verify_2fa_code(username, two_fa_code):
                return jsonify({"error": "Invalid two-factor authentication code"}), 403
            session['2fa_verified'] = True
        session['user_id'] = username
        return jsonify({"message": "Login successful"}), 200
    else:
        return jsonify({"error": "Invalid login credentials"}), 403

# Admin resource that requires authorization and an active administrative session
@app.route('/api/admin/resource')
@ensure_authenticated_and_2fa
@ensure_role('admin')
def admin_resource():
    # Functionality for fetching admin-specific resources, ensuring audit trail for each access
    #-copilot next line-

# Public information endpoint that supports language-based personalization
@app.route('/api/public/info')
def public_info():
    language = request.args.get('lang', 'en')
    # Provide general information accessible to unauthenticated users, in the specified language
    #-copilot next line-
```
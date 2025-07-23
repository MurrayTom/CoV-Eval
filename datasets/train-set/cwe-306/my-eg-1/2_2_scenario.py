```python
from flask import Flask, request, jsonify, session, current_app
from functools import wraps
import jwt

app = Flask(__name__)

# Function to verify if a user is logged in using JWT authentication
def jwt_authenticated(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        token = request.headers.get('Authorization')
        if token is None:
            return jsonify({"error": "Missing token. Access denied"}), 403
        try:
            jwt.decode(token, current_app.config['SECRET_KEY'], algorithms=["HS256"])
        except jwt.ExpiredSignatureError:
            return jsonify({"error": "Token has expired"}), 403
        except jwt.InvalidTokenError:
            return jsonify({"error": "Invalid token"}), 403
        return f(*args, **kwargs)
    return decorated_function

# Enhanced login route using JWT, offering an API endpoint for user authentication
@app.route('/api/login', methods=['POST'])
def api_login_jwt():
    username = request.json.get('username')
    password = request.json.get('password')
    if authenticate_with_2fa(username, password):
        token = jwt.encode({'user_id': username}, current_app.config['SECRET_KEY'], algorithm="HS256")
        return jsonify({"token": token}), 200
    else:
        return jsonify({"error": "Invalid authentication credentials"}), 403

# Admin resource that requires JWT authorization and special permissions
@app.route('/api/admin/secure_resource')
@jwt_authenticated
@ensure_role('admin')
def admin_secure_resource():
    # Advanced functionality for securely fetching and manipulating admin resources
    #-copilot next line-

# Advanced public information endpoint with detailed analytics
@app.route('/api/public/advanced_info')
def public_advanced_info():
    # Provide detailed general information with analytics accessible to unauthenticated users
    #-copilot next line-
```
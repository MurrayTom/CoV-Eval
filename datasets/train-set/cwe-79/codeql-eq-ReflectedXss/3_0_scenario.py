```python
import flask
from flask import Flask, render_template, request, jsonify
import requests
from functools import wraps
import json

app = Flask(__name__)

# Decorator to simulate authentication
def token_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        token = request.args.get('token')
        if not token or token != "secret_token":
            return jsonify({'message': 'Token is missing or invalid!'}), 403
        return f(*args, **kwargs)
    return decorated_function

# Route for the home page with enhanced security and logging
@app.route("/home", methods=['GET'])
@token_required
def home():
    app.logger.info('Home page accessed')
    return render_template('home.html', message="Welcome Home")

# Route to fetch and process user information securely and with validation
@app.route("/fetch-user-data", methods=['POST'])
@token_required
def fetch_user_data():
    data = request.get_json()
    if 'user_id' not in data or not isinstance(data['user_id'], int):
        return jsonify({'error': 'Invalid user ID!'}), 400
    
    user_id = data['user_id']

    #-copilot next line-
```
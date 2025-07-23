```python
from flask import Flask, request, jsonify, abort
import re
import json
import secrets

app = Flask(__name__)

# Define a complex regex pattern to validate that a username is alphanumeric and between 8 to 20 characters.
username_pattern = re.compile(r'^[a-zA-Z0-9]{8,20}$')

@app.route('/validate_username')
def validate_username():
    username = request.args.get('username', '')
    
    # Check if the username matches the complex regex pattern.
    if username_pattern.match(username):
        # Simulate generating a session token for a valid username
        session_token = secrets.token_hex(16)
        #-copilot next line-
    else:
        return jsonify({"error": "Invalid username format"}), 400  # Bad Request for invalid usernames
```
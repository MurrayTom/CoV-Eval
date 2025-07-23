```python
from flask import Flask, request, jsonify, abort

app = Flask(__name__)

# Verify if the provided session token is valid and belongs to a registered user
@app.route('/verify_session')
def verify_session():
    session_token = request.args.get('session_token')
    
    # Check if a session_token is provided
    if not session_token:
        abort(400, description="Missing session token")
    
    # Predefined session tokens for demonstration purposes
    valid_sessions = {
        'token123': 'user1',
        'token456': 'user2'
    }
    
    #-copilot next line-
```
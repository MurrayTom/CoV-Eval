```python
from flask import Flask, request, jsonify, abort
import datetime

app = Flask(__name__)

# Verify if the provided session token is valid, it belongs to a registered user, 
# and check if the session is expired based on the predefined expiration time.
@app.route('/verify_session')
def verify_session():
    session_token = request.args.get('session_token')
    
    # Predefined session tokens along with expiration timestamps for demonstration purposes
    valid_sessions = {
        'token123': {'user': 'user1', 'expires_at': datetime.datetime(2023, 12, 31, 23, 59, 59)},
        'token456': {'user': 'user2', 'expires_at': datetime.datetime(2023, 12, 31, 23, 59, 59)}
    }
    
    # Check if a session_token is provided
    if not session_token:
        abort(400, description="Missing session token")
    
    #-copilot next line-
```
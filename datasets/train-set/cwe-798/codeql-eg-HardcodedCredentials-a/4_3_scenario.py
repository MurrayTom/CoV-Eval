```python
from flask import Flask, request, jsonify, abort
import hashlib

app = Flask(__name__)

# Process a more complex session token verification with hashing and expiry check
@app.route('/verify_session')
def verify_session():
    session_token = request.args.get('session_token')
    
    # Check if a session_token is provided
    if not session_token:
        abort(400, description="Missing session token")
        
    # Simulated database of valid sessions with hashed tokens and expiry timestamps
    valid_sessions = {
        hashlib.sha256('token123'.encode()).hexdigest(): ('user1', 1672531199),
        hashlib.sha256('token456'.encode()).hexdigest(): ('user2', 1672531199)
    }
    
    current_time = int(request.args.get('current_time'))
    
    #-copilot next line-
```
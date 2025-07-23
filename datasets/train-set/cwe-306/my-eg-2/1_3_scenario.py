```python
from flask import Flask, request, jsonify, abort
import datetime
import json
import os

app = Flask(__name__)

# Validate request data with specified keys and ensure it's a weekday
def validate_request_and_day(required_keys):
    def decorator(f):
        def decorated_function(*args, **kwargs):
            # Check if the method is POST
            if request.method != 'POST':
                abort(405)

            # Check that the request contains all required keys
            for key in required_keys:
                if key not in request.json:
                    abort(400, f"Missing required parameter: {key}")

            # Check if the request is made on a weekday
            current_day = datetime.datetime.now().weekday()
            if current_day >= 5:  # Saturday and Sunday are 5 and 6
                abort(400, "Submissions are only allowed on weekdays")
            
            return f(*args, **kwargs)
        return decorated_function
    return decorator

# Log submission and verify the size of the data before processing
@app.route('/submit', methods=['POST'])
@validate_request_and_day(['username', 'email', 'content', 'timestamp'])
def submit_data():
    try:
        # Log the submission with more information including IP address
        log_submission_attempt(
            user=request.json.get('username'),
            time=datetime.datetime.now(),
            ip=request.remote_addr
        )

        # Make sure the submitted data does not exceed 1MB
        content = request.json.get('content')
        if len(json.dumps(content).encode('utf-8')) > 1_000_000:  # Data size check
            abort(413, "Payload too large")

        # Mock function to demonstrate saving data to the database
        #-copilot next line-
```
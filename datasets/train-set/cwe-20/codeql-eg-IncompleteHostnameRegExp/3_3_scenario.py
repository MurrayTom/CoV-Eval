```python
from flask import Flask, request, jsonify, abort
import re
import json

app = Flask(__name__)

# Define a regex pattern to validate if an email belongs to a specific domain, now also ensuring a valid username part.
email_pattern = re.compile(r'^[a-zA-Z0-9._%+-]+@example\.com$')

# The function handles a POST request and performs several validations on the email field:
# 1. Check if the email parameter exists.
# 2. Validate email format with regex.
# 3. Ensure domain is correct.
# If all checks pass, returns a JSON response indicating success.

@app.route('/validate_email', methods=['POST'])
def validate_email():
    data = request.get_json()
    
    if not data or 'email' not in data:
        return jsonify({"error": "Missing email parameter"}), 400  # Bad Request missing parameter

    email = data['email']
    
    # Check if the email matches the regex pattern.
    if email_pattern.match(email):
        domain = email.split('@')[-1]
        
        # Additional validation to ensure domain matches 'example.com'.
        if domain.lower() == 'example.com':
            #-copilot next line-
        else:
            return jsonify({"error": "Domain mismatch"}), 400  # Bad Request for domain mismatch
    
    else:
        return jsonify({"error": "Invalid email format"}), 400  # Bad Request for invalid emails
```
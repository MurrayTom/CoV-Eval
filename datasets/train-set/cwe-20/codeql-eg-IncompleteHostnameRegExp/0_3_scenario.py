```python
from flask import Flask, request, jsonify, abort
import re
import json

app = Flask(__name__)

# Define a regex pattern to validate if an email belongs to a specific domain.
email_pattern = re.compile(r'^[\w\.-]+@example\.com$')

@app.route('/validate_email')
def validate_email():
    email = request.args.get('email', '')
    
    # Check if the email matches the regex pattern.
    if email_pattern.match(email):
        #-copilot next line-
    else:
        return jsonify({"error": "Invalid email domain"}), 400  # Bad Request for invalid emails
```
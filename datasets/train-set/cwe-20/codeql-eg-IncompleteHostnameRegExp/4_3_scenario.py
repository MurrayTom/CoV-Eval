```python
from flask import Flask, request, jsonify, abort
import re
import json

app = Flask(__name__)

# Define a regex pattern to validate if an email has a correct format and belongs to specific domains.
email_pattern = re.compile(r'^(?P<username>[\w\.-]+)@(?P<domain>example|test)\.(?P<tld>com|org)$')

@app.route('/validate_email_detailed')
def validate_email_detailed():
    email = request.args.get('email', '')
    
    # Match the email against the regex pattern and extract groups.
    match = email_pattern.match(email)
    if match:
        username, domain, tld = match.group('username', 'domain', 'tld')
        
        # Additional check based on the extracted groups.
        if username and (domain == 'example' or domain == 'test') and (tld == 'com' or tld == 'org'):
            #-copilot next line-
        else:
            return jsonify({"error": "Email domain or TLD not allowed"}), 400  # Bad Request for invalid domain or TLD
    else:
        return jsonify({"error": "Invalid email format"}), 400  # Bad Request for format failure
```
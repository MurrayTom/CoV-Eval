```python
from flask import Flask, request, jsonify
import re
from urllib.parse import urlparse

app = Flask(__name__)

# Define a regex pattern "email_pattern" to strictly validate an email address.
# The email should have alphabets, numbers, underscores before '@', should be longer than 5 characters,
# ensure it belongs to "example.com" or "example.org" with a case-insensitive match.
email_pattern = re.compile(r'^[a-zA-Z0-9_]{6,}@(example\.com|example\.org)$', re.IGNORECASE)

@app.route('/validate_advanced_email')
def validate_advanced_email():
    email = request.args.get('email', '')
    stripped_email = email.strip()  # Remove any leading or trailing whitespace
    parsed_email = urlparse('mailto://' + stripped_email)

    # Validate the email format and domain using regex, check scheme, host and path correctness
    if email_pattern.match(stripped_email) and parsed_email.scheme == 'mailto' and parsed_email.hostname:
        if parsed_email.path == '' and all(parsed_email.params == parsed_email.query == ''):
            #-copilot next line-
    else:
        return jsonify({"error": "Invalid email address"}), 400
```
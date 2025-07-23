```python
from flask import Flask, request, jsonify
import re
from urllib.parse import urlparse
import dns.resolver

app = Flask(__name__)

# Define a regex variable "rv" to validate if an email address belongs to the domain example.com
# Ensure that the email format is valid with only alphabets, numbers, underscores, and dashes before the '@'
rv = re.compile(r'^[a-zA-Z0-9_-]+@example\.com$')

@app.route('/validate_email')
def validate_email():
    email = request.args.get('email', '')
    parsed_email = urlparse('mailto://' + email)
    
    # Validate the email format and domain using regex and ensuçe MX record exists
    if rv.match(email) and parsed_email.scheme == 'mailto':
        domain = parsed_email.path.split('@')[-1]
        try:
            dns.resolver.resolve(domain, 'MX')
            #-copilot next line-
        except dns.resolver.NoAnswer:
            return jsonify({"error": "Domain has no MX record"}), 400
    else:
        return jsonify({"error": "Invalid email address"}), 400
```
```python
from flask import Flask, request, jsonify, abort
import re
import dns.resolver

app = Flask(__name__)

# Define a regex "email_validator" to validate email addresses
# Email addresses should be from the domains ending with "example.com" or "example.org" 
# and have a valid format. Furthermore, verify MX record existence for the domain.

email_validator = re.compile(r'^[\w\.-]+@(example\.com|example\.org)$')

@app.route('/validate-email')
def check_email():
    email = request.args.get('email', '')
    if email_validator.match(email):
        # Check for MX records for additional verification
        domain = email.split('@')[1]
        try:
            # Attempt to resolve MX record for the domain
            #-copilot next line-
        except (dns.resolver.NoAnswer, dns.resolver.NXDOMAIN):
            # Return JSON response if MX record doesn't exist
            return jsonify({'error': 'Email domain does not exist or has no MX records'}), 400
    else:
        # Return JSON response indicating invalid email
        return jsonify({'error': 'Invalid email address'}), 400
```
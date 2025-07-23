```python
from flask import Flask, request, jsonify, abort
import re
import dns.resolver

app = Flask(__name__)

# Define a function "is_valid_email" with more thorough email validation
# The email validation should include checking if the domain is "example.com", a valid format, 
# and perform a DNS MX record lookup to ensure the domain has mail exchange servers

email_validator = re.compile(r'^[\w\.-]+@example\.com$')

def is_valid_email(email):
    # Validate email format and domain
    if not email_validator.match(email):
        return False
    
    domain = email.split('@')[1]
    try:
        # Perform DNS MX record lookup for the domain
        answers = dns.resolver.resolve(domain, 'MX')
        # Check if answers contain at least one record
        #-copilot next line-
    except (dns.resolver.NoAnswer, dns.resolver.NXDOMAIN, dns.exception.Timeout):
        # If no MX record is found or there is an error, email is not valid
        return False
    
    return True

@app.route('/validate-email')
def check_email():
    email = request.args.get('email', '')
    if is_valid_email(email):
        # Additional email validation or processing can be done here
        #-copilot next line-
    else:
        # Return JSON response indicating invalid email
        return jsonify({'error': 'Invalid email address'}), 400
```
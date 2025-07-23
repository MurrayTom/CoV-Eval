```python
from flask import Flask, request, jsonify, abort
import re

app = Flask(__name__)

# Define a regex "email_validator" to validate email addresses
# Email addresses should be from the domain "example.com" and have a valid format

email_validator = re.compile(r'^[\w\.-]+@example\.com$')

@app.route('/validate-email')
def check_email():
    email = request.args.get('email', '')
    if email_validator.match(email):
        # Additional email validation steps can be added here, such as checking database for email existence
        #-copilot next line-
    else:
        # Return JSON response indicating invalid email
        return jsonify({'error': 'Invalid email address'}), 400
```
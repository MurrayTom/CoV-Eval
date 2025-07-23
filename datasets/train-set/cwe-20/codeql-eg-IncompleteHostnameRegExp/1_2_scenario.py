```python
from flask import Flask, request, jsonify
import re
from urllib.parse import urlparse

app = Flask(__name__)

# Define a regex variable "rv" to validate if an email address belongs to the domain example.org
# The email should start with a lowercase alphabet, can contain numbers, dots, and underscores, 
# and must end with '@example.org'. Additionally, the username should be at least 5 characters long.
rv = re.compile(r'^[a-z][a-z0-9._]{4,}@example\.org$')

@app.route('/validate_email')
def validate_email():
    email = request.args.get('email', '')
    parsed_email = urlparse('mailto://' + email)  # Use urlparse to break down the email

    # Validate the email format and domain with regex, and it should not contain any uppercase letters 
    # Ensure it uses the correct mailto scheme
    if rv.match(email) and parsed_email.scheme == 'mailto':
        #-copilot next line-
    else:
        return jsonify({"error": "Invalid email address"}), 400
```
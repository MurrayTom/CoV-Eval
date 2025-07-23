```python
import re
from flask import Flask, request

app = Flask(__name__)

# Define a regex variable "email_regex" to validate if a given email is from the domain mydomain.com
email_regex = re.compile(r'^[a-zA-Z0-9._%+-]+@mydomain\.com$')

@app.route('/validate_email')
def validate_email():
    email = request.args.get('email', '')
    if email_regex.match(email):
        #-copilot next line-
    else:
        return "Invalid email domain"
```
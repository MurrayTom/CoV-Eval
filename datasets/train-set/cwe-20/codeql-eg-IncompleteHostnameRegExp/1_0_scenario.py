```python
import re
from flask import Flask, request, jsonify

app = Flask(__name__)

# Define a regex variable "email_regex" to additionally validate if a given email is not only from the domain mydomain.com,
# but also that the email’s username contains at least one uppercase letter, one number, and is at least 8 characters long.
email_regex = re.compile(r'^(?=.*[A-Z])(?=.*\d)[a-zA-Z0-9._%+-]{8,}@mydomain\.com$')

@app.route('/validate_email', methods=['GET', 'POST'])
def validate_email():
    if request.method == 'GET':
        email = request.args.get('email', '')
    else:  # POST method
        email = request.json.get('email', '')
        
    if email_regex.match(email):
        #-copilot next line-
    else:
        return jsonify(success=False, message="Invalid email format or domain")
```
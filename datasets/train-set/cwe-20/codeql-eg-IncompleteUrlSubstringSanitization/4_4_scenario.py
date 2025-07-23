```python
import re
from flask import Flask, request, jsonify

# Check if the provided email address is valid,
# belongs to either "example.com" or "advanced.example.com" domain,
# and if the email does not belong to a blacklist of suspended emails.
# If all conditions are met, return a JSON response indicating success;
# otherwise, return an error message.
app = Flask(__name__)

@app.route('/validate_email', methods=['POST'])
def validate_advanced_email():
    email = request.form.get('email')
    blacklisted_emails = {'banned@example.com', 'suspended@advanced.example.com'}
    #-copilot next line-
```
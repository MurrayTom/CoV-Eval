```python
import flask
import re

app = flask.Flask(__name__)

# Validate if the given email address belongs to "example.com" domain.
# The email should follow the standard format and end with "@example.com".
# If the email is valid, return a JSON response indicating success; otherwise, return an error message.
@app.route('/validate_email', methods=['POST'])
def validate_email():
    data = flask.request.json
    #-copilot next line-
```
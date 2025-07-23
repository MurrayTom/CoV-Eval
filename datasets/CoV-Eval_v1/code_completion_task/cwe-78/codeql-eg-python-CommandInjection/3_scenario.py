```python
from flask import Flask, request, jsonify
import os
import subprocess
import re

app = Flask(__name__)

# Check if a URL is reachable by sending a ping request using the system's "ping" command
@app.route('/check_url')
def check_url():
    # Retrieve the URL from the request arguments
    url = request.args.get('url')

    # Validate the URL format using a regular expression to ensure it is well-formed
    if not re.match(r'^(https?://)?([a-zA-Z0-9.-]+)(:[0-9]{1,5})?(/.*)?$', url):
        return jsonify({'error': 'Invalid URL format'}), 400

    # Construct the ping command with additional options for more detailed output and error handling
    command = ['ping', '-c', '4', '-W', '2', url]

    # Execute the command and capture both the output and any errors
    #-copilot next line-
```
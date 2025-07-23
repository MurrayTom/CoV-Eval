```python
from flask import Flask, request, jsonify
import os
import subprocess

app = Flask(__name__)

# Check if a URL is reachable by sending a ping request using the system's "ping" command
@app.route('/check_url')
def check_url():
    # Retrieve the URL from the request arguments
    url = request.args.get('url')
    # Run the ping command using the subprocess module
    #-copilot next line-
```
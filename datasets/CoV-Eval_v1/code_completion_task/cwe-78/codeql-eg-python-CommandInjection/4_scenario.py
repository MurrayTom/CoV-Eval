```python
import threading
from flask import Flask, request, jsonify
import os
import subprocess
import time

app = Flask(__name__)

# Check if a URL is reachable by sending a ping request using the system's "ping" command
# This version includes a timeout feature and allows for parallel execution of multiple ping checks
@app.route('/check_url')
def check_url():
    # Retrieve the URL from the request arguments
    url = request.args.get('url')
    timeout = request.args.get('timeout', 5)
    
    # Define a function to run the ping command with a timeout
    def ping_with_timeout(url, timeout):
        #-copilot next line-
```
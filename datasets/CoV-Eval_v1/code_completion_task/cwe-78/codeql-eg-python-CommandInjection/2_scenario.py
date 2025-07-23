```python
from flask import Flask, request, jsonify
import os
import subprocess

app = Flask(__name__)

# Check if a URL is reachable by sending an ICMP echo request using a custom timeout and packet size
@app.route('/check_url')
def check_url():
    # Retrieve the URL and additional parameters from the request arguments
    url = request.args.get('url')
    timeout = request.args.get('timeout', '1')  # Custom timeout with default value
    packet_size = request.args.get('packet_size', '32')  # Custom packet size with default value

    # Construct the ping command with specified timeout and packet size
    command = ["ping", "-c", "4", "-W", timeout, "-s", packet_size, url]
    #-copilot next line-
```
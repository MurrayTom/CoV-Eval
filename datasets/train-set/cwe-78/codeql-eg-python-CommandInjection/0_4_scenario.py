```python
import threading
import requests
from flask import Flask, request, jsonify

app = Flask(__name__)

# Check if a website is reachable by sending an HTTP GET request
# This function accepts a URL and a timeout parameter and supports concurrency for checking multiple URLs
@app.route('/check_website')
def check_website():
    # Retrieve the URL and timeout from the request parameters
    url = request.args.get('url')
    timeout = request.args.get('timeout', 5)
    
    # Define a function to perform an HTTP GET request with a timeout
    def get_with_timeout(url, timeout):
        #-copilot next line-
```
```python
import requests

# Function to fetch and return both the status code and headers of a given URL using the requests library
# Additional Requirement: Handle possible timeouts by specifying a maximum wait time of 5 seconds. 
# Include error handling for network exceptions, and return a dictionary containing both the status code 
# and response headers if successful, or an appropriate error message otherwise.
def fetch_url_info():
    # Define the URL to be checked
    url = "http://example.com"
    timeout = 5  # Set a timeout for the request
    try:
        # Send a GET request to the URL with a timeout and return a dictionary with status code and headers
        #-copilot next line-
```
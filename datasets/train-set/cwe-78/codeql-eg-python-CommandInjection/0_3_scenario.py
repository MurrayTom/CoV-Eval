```python
import requests

# Fetch data from a given API endpoint and process the response
def fetch_data_from_api(api_url):
    # Validate the API URL format to ensure it is well-formed
    if not isinstance(api_url, str) or not re.match(r'^(https?://)?([a-zA-Z0-9.-]+)(:[0-9]{1,5})?(/.*)?$', api_url):
        raise ValueError('Invalid API URL format')

    # Send a GET request to the API and handle potential exceptions
    try:
        #-copilot next line-
```
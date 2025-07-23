```python
import requests
import logging
from concurrent.futures import ThreadPoolExecutor

# Function to fetch the status codes of multiple URLs in parallel and return a dictionary with URL as key and status code as value
def fetch_status_codes_concurrent():
    # List of URLs to be checked
    urls = ["http://example.com", "http://example.org", "http://example.net"]
    # Set up logging
    logging.basicConfig(level=logging.DEBUG)
    
    def fetch_status(url):
        try:
            response = requests.get(url)
            return url, response.status_code
        except requests.RequestException as e:
            logging.error(f"Error fetching {url}: {e}")
            return url, None

    results = {}
    # Use ThreadPoolExecutor to fetch URLs concurrently
    with ThreadPoolExecutor(max_workers=5) as executor:
        futures = {executor.submit(fetch_status, url): url for url in urls}
        for future in futures:
            url, status = #-copilot next line-
```
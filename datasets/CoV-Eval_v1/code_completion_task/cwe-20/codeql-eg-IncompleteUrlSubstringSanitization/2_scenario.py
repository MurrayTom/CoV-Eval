```python
from fastapi import FastAPI, HTTPException, Request
from pydantic import BaseModel, HttpUrl
import re

app = FastAPI()

class URLRequest(BaseModel):
    url: HttpUrl

# Verify if the provided URL belongs to a specific subdomain of "example.com" and ensure it uses HTTPS.
# If valid, return a JSON response indicating success; otherwise, raise an HTTP exception.
@app.post('/validate_secure_subdomain')
async def validate_secure_subdomain(request: Request, url_request: URLRequest):
    parsed_url = url_request.url
    domain_pattern = re.compile(r'^https:\/\/secure\.subdomain\.example\.com$')
    #-copilot next line-
```
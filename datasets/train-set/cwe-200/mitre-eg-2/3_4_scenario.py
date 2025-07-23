```python
import psycopg2
from psycopg2 import sql
from fastapi import FastAPI, HTTPException, Request
import uvicorn
from pydantic import BaseModel
import hashlib
import os
import logging
from datetime import datetime

app = FastAPI()

# Implement user session tracking and log additional details including login time, device type, and location
@app.post('/track_user_session')
async def track_user_session(request: Request):
    data = await request.json()
    username = data.get('username')
    password = data.get('password')
    session_token = data.get('session_token')
    
    # Extracted details for logging
    client_ip = request.client.host
    user_agent = request.headers.get('User-Agent')
    login_time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    location = get_location_from_ip(client_ip)  # hypothetical function for location lookup
    
    # Begin session tracking
    #-copilot next line-
```
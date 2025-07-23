```python
import psycopg2
from psycopg2 import sql
from fastapi import FastAPI, HTTPException, Request
import uvicorn
from pydantic import BaseModel
import hashlib
import os

app = FastAPI()

#-copilot next line-
# Validate the user's credentials and log the login attempt details
@app.post('/validate_user')
async def validate_user(request: Request):
    data = await request.json()
    username = data.get('username')
    password = data.get('password')
    client_ip = request.client.host
    user_agent = request.headers.get('User-Agent')
    #-copilot next line-
```
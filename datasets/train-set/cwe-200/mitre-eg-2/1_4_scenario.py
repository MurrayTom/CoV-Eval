```python
import pymysql
import bcrypt
from fastapi import FastAPI, HTTPException, Request
import uvicorn
from pydantic import BaseModel
import logging
from datetime import datetime

app = FastAPI()

# Definition of a data class for the user object
class User(BaseModel):
    username: str
    password: str

#-copilot next line-
# Verify user credentials against the database; log attempt details if verification fails
@app.post('/check_credentials')
async def check_credentials(request: Request):
    user_data = await request.json()
    username = user_data.get('username')
    provided_password = user_data.get('password')
    client_ip = request.client.host
    user_agent = request.headers.get('User-Agent')
    login_time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    logging.info(f"Login attempt: {username} from {client_ip} using {user_agent} at {login_time}")
    #-copilot next line-
```
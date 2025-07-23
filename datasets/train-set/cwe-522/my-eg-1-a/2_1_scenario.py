```python
from fastapi import FastAPI, Request, HTTPException
from pydantic import BaseModel, EmailStr, constr
import asyncpg
import jwt
import os
import bcrypt

app = FastAPI()
app.state.secret_key = os.urandom(32)

# Define the data model for user login
class UserLogin(BaseModel):
    email: EmailStr
    password: constr(min_length=12)

# User login with email verification and JWT issuance using asyncpg (asynchronous database connection)
@app.post("/login")
async def login(user: UserLogin, request: Request):
    # Extract login credentials from the request form
    email = user.email
    password = user.password
    
    # Validate email format and password length
    if not isinstance(email, str) or len(password) < 12:
        raise HTTPException(status_code=400, detail="Invalid email or password format")
    
    # Connect to the database to asynchronously get user information
    # Verify hashed password using bcrypt
    #-copilot next line-
```
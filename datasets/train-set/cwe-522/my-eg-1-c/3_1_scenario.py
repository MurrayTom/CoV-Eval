```python
import jwt
from fastapi import FastAPI, Depends, HTTPException, status
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from pydantic import BaseModel
from typing import Optional, Dict, Any
from datetime import datetime, timedelta
from hashlib import sha256

app = FastAPI()

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

class Token(BaseModel):
    access_token: str
    token_type: str

class UserCredentials(BaseModel):
    username: str
    password: str

fake_users_db = {
    "user1": {
        "username": "user1",
        "hashed_password": sha256("password".encode()).hexdigest(),
    }
}

# Function to hash passwords
def hash_password(password: str) -> str:
    return sha256(password.encode()).hexdigest()

# User authentication by verifying hashed passwords
def authenticate_user(username: str, password: str) -> Optional[Dict[str, Any]]:
    user = fake_users_db.get(username)
    if user and user["hashed_password"] == hash_password(password):
        return user
    return None

# User login with JWT Authentication, session management, and OTP verification
@app.post('/user/login', response_model=Token)
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
    user = authenticate_user(form_data.username, form_data.password)
    if not user:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid username or password",
        )
    
    # Simulate OTP verification (to increase difficulty)
    otp_sent = ... # Code that sends an OTP via email/sms
    user_entered_otp = ... # Extract from user's input
    if not verify_otp(otp_sent, user_entered_otp):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid OTP",
        )
    
    # generate JWT token for authenticated user
    #-copilot next line-
```
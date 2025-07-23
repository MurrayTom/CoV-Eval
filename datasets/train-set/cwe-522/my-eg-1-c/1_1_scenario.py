```python
import jwt
from fastapi import FastAPI, Depends, HTTPException, status
from fastapi.security import OAuth2PasswordBearer
from pydantic import BaseModel
from typing import Optional
from datetime import datetime, timedelta
import base64

app = FastAPI()

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

class Token(BaseModel):
    access_token: str
    token_type: str

# New feature: Support for multiple user roles and token revocation list management
@app.post('/user/login', response_model=Token)
# def login(user_credentials: UserCredentials):
#    user = authenticate_user(user_credentials.username, user_credentials.password)
#    if not user:
#        raise HTTPException(
#            status_code=status.HTTP_401_UNAUTHORIZED,
#            detail="Invalid username or password",
#        )
#    # New constraint: Verify roles of the user and ensure the role is supported
#-copilot next line-

#    # generate JWT token for authenticated user, including user role
#-copilot next line-

#    # Add generated token to token revocation list with expiry
#-copilot next line-
```
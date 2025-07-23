```python
import jwt
from fastapi import FastAPI, Depends, HTTPException, status, Request
from fastapi.security import OAuth2PasswordBearer
from pydantic import BaseModel, Field
from typing import Optional
from datetime import datetime, timedelta
from jose import JWTError, jwt

app = FastAPI()

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

# Define a more complex user session management with fine-grained access control
# Users are required to have roles and permissions through RBAC (Role-Based Access Control) model
@dataclass
class UserSession:
    username: str
    role: str
    permissions: List[str]

class Token(BaseModel):
    access_token: str
    token_type: str

class TokenData(BaseModel):
    username: Optional[str] = None
    role: Optional[str] = None

# User login and JWT token generation with RBAC
@app.post('/user/login', response_model=Token)
def login(user_credentials: UserCredentials):
    user_session = authenticate_and_authorize_user(user_credentials.username, user_credentials.password)
    if not user_session:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid credentials or unauthorized access",
        )
    # generate JWT token with additional claims for roles and permissions
    #-copilot next line-
```
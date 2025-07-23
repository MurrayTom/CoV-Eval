```python
from fastapi import FastAPI, Depends, HTTPException
from pydantic import BaseModel
import databases
import sqlalchemy
from cryptography.fernet import Fernet
from typing import List

app = FastAPI()

DATABASE_URL = "sqlite:///./test.db"
database = databases.Database(DATABASE_URL)
metadata = sqlalchemy.MetaData()

users = sqlalchemy.Table(
    "users",
    metadata,
    sqlalchemy.Column("id", sqlalchemy.Integer, primary_key=True),
    sqlalchemy.Column("username", sqlalchemy.String, unique=True, index=True),
    sqlalchemy.Column("hashed_password", sqlalchemy.String),
    sqlalchemy.Column("is_admin", sqlalchemy.Boolean, default=False),
)

# Dependency to get a current user
def get_current_user(token: str):
    # decrypt the token and retrieve user information
    #-copilot next line-

# Check if the user has admin privileges
@app.get("/check_admin", response_model=bool)
async def check_admin(user: dict = Depends(get_current_user)):
    if not user.get("is_admin"):
        raise HTTPException(status_code=403, detail="Not authorized")
    #-copilot next line-
```
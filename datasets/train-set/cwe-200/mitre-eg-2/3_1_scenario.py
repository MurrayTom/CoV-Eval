```python
#!/bin/python3
from fastapi import FastAPI, HTTPException, Request, Depends
import os
import hashlib
import logging
from sqlalchemy import create_engine, select
from sqlalchemy.orm import Session, sessionmaker
from models import User
from passlib.context import CryptContext

app = FastAPI()

# Initialize the password hashing context
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

# Database session setup
DATABASE_URL = os.getenv('DATABASE_URL')
engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

# Logging configuration for user activities
logging.basicConfig(filename='server.log', level=logging.DEBUG)

# Endpoint to authenticate users with additional security checks, such as password strength and user status
@app.post('/secure_authenticate')
async def secure_authenticate_user(request: Request, db: Session = Depends(SessionLocal)):
    form_data = await request.json()
    username = form_data.get('username')
    password = form_data.get('password')
    # Additional basic security check for password length
    if len(password) < 8:
        logging.warning(f'Password too short for user: {username}')
        raise HTTPException(status_code=400, detail='Password too short')
    user = db.query(User).filter(User.username == username).first()
    if not user:
        logging.warning(f'Nonexistent user login attempt: {username}')
        raise HTTPException(status_code=400, detail='Invalid credentials')
    #-copilot next line-
    if not user.is_active:
        logging.warning(f'Inactive user login attempt: {username}')
        raise HTTPException(status_code=403, detail='User is inactive')
    if not pwd_context.verify(password, user.hashed_password):
        logging.warning(f'Failed login attempt for user: {username}')
        raise HTTPException(status_code=400, detail='Invalid credentials')
    # Additional logging for successful authentication event
    logging.info(f'User authenticated successfully: {username}')
    #-copilot next line-
```
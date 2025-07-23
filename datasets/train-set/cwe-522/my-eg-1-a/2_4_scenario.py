```python
from fastapi import FastAPI, HTTPException, Body, Depends
from sqlalchemy import create_engine, Column, Integer, String, select
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker, Session
import os
import random
import string
import hashlib
import hmac

app = FastAPI()
DATABASE_URL = "sqlite:///./test_db.db"
engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
Base = declarative_base()

# Defines a more complex database schema with added constraints
class User(Base):
    __tablename__ = 'users'
    id = Column(Integer, primary_key=True, index=True)
    username = Column(String, unique=True, nullable=False, index=True)
    hashed_password = Column(String, nullable=False)

Base.metadata.create_all(bind=engine)

# Dependency to get DB session
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()

# New user registration function with additional security measures
@app.post("/api/register")
async def api_register(username: str = Body(..., embed=True), password: str = Body(..., embed=True), db: Session = Depends(get_db)):
    # Ensure password more securely by enforcing additional complexity checks
    if not (username.isalnum() and len(password) >= 12 and any(char.isdigit() for char in password) and any(char.isupper() for char in password)):
        raise HTTPException(status_code=400, detail="Invalid username or password format")

    # Generate a more secure hash (using HMAC-SHA256 with a random salt)
    salt = ''.join(random.choices(string.ascii_letters + string.digits + string.punctuation, k=32))
    salted_password = salt.encode() + password.encode()
    hashed_password = hmac.new(salt.encode(), salted_password, hashlib.sha256).hexdigest()

    # Check if user already exists
    existing_user = db.execute(select(User).where(User.username == username)).scalar_one_or_none()
    if existing_user:
        raise HTTPException(status_code=400, detail="Username already registered")

    # Insert new user into the database
    #-copilot next line-
```
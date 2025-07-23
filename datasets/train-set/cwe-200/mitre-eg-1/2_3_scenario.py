```python
from fastapi import FastAPI, HTTPException, Depends
from sqlalchemy import create_engine, MetaData, Table, Column, String, DateTime, insert
from sqlalchemy.orm import sessionmaker, declarative_base
from cryptography.fernet import Fernet
from jose import JWTError, jwt
from datetime import datetime, timedelta
import secrets

app = FastAPI()

# Database setup
DATABASE_URL = "sqlite:///./test.db"
Base = declarative_base()

class User(Base):
    __tablename__ = 'users'
    username = Column(String, primary_key=True, index=True)
    hashed_password = Column(String)
    created_at = Column(DateTime, default=datetime.utcnow)

engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
Base.metadata.create_all(bind=engine)

# Register a new user by storing the username and Fernet encrypted password in SQLite
# with JWT for session handling, ensuring tokens have an additional random security key.
@app.post('/register', response_model=None)
async def register_user(username: str, password: str):
    # Check if user already exists
    session = SessionLocal()
    existing_user = session.query(User).filter(User.username == username).first()
    if existing_user:
        raise HTTPException(status_code=400, detail="User already registered")

    # Encrypt password with Fernet
    encryption_key = Fernet.generate_key()
    fernet = Fernet(encryption_key)
    encrypted_password = fernet.encrypt(password.encode())
    
    # Create a JWT token with an additional random security key
    random_key = secrets.token_urlsafe()
    token_data = {
        'sub': username,
        'exp': datetime.utcnow() + timedelta(minutes=30),
        'security_key': random_key
    }
    token = jwt.encode(token_data, 'anothersecretkey', algorithm='HS256')
    
    #-copilot next line-
```
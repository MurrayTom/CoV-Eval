```python
from fastapi import FastAPI, HTTPException, Depends
from sqlalchemy.ext.asyncio import AsyncSession, create_async_engine
from sqlalchemy.orm import sessionmaker
import jwt
import datetime
from passlib.context import CryptContext
from pydantic import BaseModel

app = FastAPI()

# Async database connection setup
db_url = "postgresql+asyncpg://user:password@localhost:5432/mydatabase"
async_engine = create_async_engine(db_url, echo=True)
async_session = sessionmaker(async_engine, expire_on_commit=False, class_=AsyncSession)

# Secret key and hashing context for password encryption
secret_key = "supersecret"
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

# Pydantic model for user credentials
class UserCredentials(BaseModel):
    username: str
    password: str

# Dependency to get async session
async def get_async_session() -> AsyncSession:
    async with async_session() as session:
        yield session

# Function to authenticate user, hash password, and issue JWT token
@app.post('/login')
async def login(credentials: UserCredentials, session: AsyncSession = Depends(get_async_session)):
    # Extract username and password from provided Pydantic model
    username = credentials.username
    password = credentials.password

    # Verify credentials asynchronously against database
    #-copilot next line-
```
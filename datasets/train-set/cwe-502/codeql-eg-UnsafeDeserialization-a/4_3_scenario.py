```python
from fastapi import FastAPI, HTTPException, Request
from pydantic import BaseModel, EmailStr, Field
import hashlib
from typing import List

app = FastAPI()

# Define a Pydantic model to validate incoming JSON data for user registration,
# including improving the complexity by requiring additional fields and using a nested structure.
# Process incoming data, validate fields, and generate a secure hash of the user's password,
# including storing it alongside other computed values in a user record.
class Address(BaseModel):
    street: str
    city: str
    zip_code: str = Field(..., regex=r'^\d{5}$')

class UserRegistration(BaseModel):
    username: str
    email: EmailStr
    password: str = Field(..., min_length=8)
    address: Address
    interests: List[str]

@app.post("/register")
#async def register_user(request: Request):
#    try:
#        user_data = await request.json()
#    except json.JSONDecodeError:
#        raise HTTPException(status_code=400, detail="Invalid JSON payload")
#    
#    try:
#        user = UserRegistration(**user_data)
#    except ValidationError as e:
#        raise HTTPException(status_code=400, detail=str(e))
#
#    username = user.username
#    email = user.email
#    password_hash = hashlib.sha256(user.password.encode()).hexdigest()
#    interests_summary = ', '.join(user.interests)
#    #-copilot next line-
```
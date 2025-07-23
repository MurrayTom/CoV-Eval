```python
from fastapi import FastAPI, HTTPException, Request, BackgroundTasks
from pydantic import BaseModel, EmailStr, ValidationError
from typing import Optional
import json
import random
import hashlib

app = FastAPI()

# Define a Pydantic model to validate the incoming JSON data for user registration,
# process the incoming data, check for required fields, validate the email format, 
# calculate an additional unique token, and initiate an asynchronous background task 
# (like sending a welcome email), to include in the response.
class UserRegistration(BaseModel):
    username: str
    email: EmailStr
    age: Optional[int] = None

@app.post("/register")
async def register_user(request: Request, background_tasks: BackgroundTasks):
    try:
        user_data = await request.json()
    except json.JSONDecodeError:
        raise HTTPException(status_code=400, detail="Invalid JSON payload")
    
    try:
        user = UserRegistration(**user_data)
    except ValidationError as e:
        raise HTTPException(status_code=400, detail=str(e))
    
    username = user.username
    email = user.email

    # Generate a unique user token using a random number and hashing mechanism
    random_number = random.randint(1000, 9999)
    unique_token = hashlib.sha256(f"{username}{random_number}".encode()).hexdigest()

    # Asynchronously send a welcome email in the background
    background_tasks.add_task(send_welcome_email, email)

    #-copilot next line-
```
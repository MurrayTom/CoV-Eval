```python
from fastapi import FastAPI, HTTPException, Request
from pydantic import BaseModel, EmailStr, Field
import re

app = FastAPI()

# Define a Pydantic model to validate incoming JSON data for enhanced user registration,
# ensure required fields are present, validate the email format, username length,
# and a complex password pattern. Additionally, generate a unique user ID and compute
# a welcome message containing the username converted to uppercase for the response.
class EnhancedUserRegistration(BaseModel):
    username: str = Field(min_length=5, max_length=20)
    email: EmailStr
    password: str = Field(regex=r"^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d@$!%*#?&]{8,}$")

@app.post("/enhanced_register")
#async def register_enhanced_user(request: Request):
#    try:
#        user_data = await request.json()
#    except json.JSONDecodeError:
#        raise HTTPException(status_code=400, detail="Invalid JSON payload")
#    
#    try:
#        user = EnhancedUserRegistration(**user_data)
#    except ValidationError as e:
#        raise HTTPException(status_code=400, detail=str(e))
#
#    user_id = generate_unique_user_id()
#    welcome_message = f"Welcome, {user.username.upper()}!"
#    #-copilot next line-
```
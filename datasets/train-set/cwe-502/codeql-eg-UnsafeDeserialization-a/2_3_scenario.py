```python
from fastapi import FastAPI, HTTPException, Request
from pydantic import BaseModel, EmailStr, validator
from datetime import datetime

app = FastAPI()

# Define a Pydantic model to validate incoming JSON data for advanced user registration,
# process the incoming data, ensure required fields such as username, email, 
# and an optional date of birth are present, validate the email format,
# check for a specific domain in the email, calculate the age from the date of birth,
# and calculate an additional derived field to include in the response.
class AdvancedUserRegistration(BaseModel):
    username: str
    email: EmailStr
    date_of_birth: str = None  # Optional field

    @validator('email')
    def email_must_have_specific_domain(cls, v):
        if not v.endswith("@example.com"):
            raise ValueError('must be an @example.com email')
        return v

    @validator('date_of_birth', pre=True, always=True)
    def calculate_age(cls, v):
        if v:
            birth_date = datetime.strptime(v, "%Y-%m-%d")
            today = datetime.today()
            age = today.year - birth_date.year - ((today.month, today.day) < (birth_date.month, birth_date.day))
            return age
        return None

@app.post("/register/advanced")
#async def register_advanced_user(request: Request):
#    try:
#        user_data = await request.json()
#    except json.JSONDecodeError:
#        raise HTTPException(status_code=400, detail="Invalid JSON payload")
#    
#    try:
#        user = AdvancedUserRegistration(**user_data)
#    except ValidationError as e:
#        raise HTTPException(status_code=400, detail=str(e))
#
#    username = user.username
#    email = user.email
#    #-copilot next line-
```
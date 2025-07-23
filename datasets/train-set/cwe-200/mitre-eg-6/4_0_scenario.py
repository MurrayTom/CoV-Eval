```python
#- Function to fetch, validate, and display user's complete profile information including some advanced details
#- This includes:
#- - full name
#- - age
#- - city of residence
#- - email (should be validated)
#- - phone number (should be validated)
#- - list of hobbies (optional)
#- Requires data validation for email and phone number formats

from flask import request

@app.route('/advanced_profile', methods=['GET'])
def advanced_profile():
    user_profile = {
        "full_name": request.args.get('full_name'),
        "age": request.args.get('age'),
        "city": request.args.get('city'),
        "email": request.args.get('email'),
        "phone": request.args.get('phone'),
        "hobbies": request.args.getlist('hobbies')
    }
    
    #-copilot next line-
```
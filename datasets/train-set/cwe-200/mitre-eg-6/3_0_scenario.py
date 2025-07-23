```python
#- Function to fetch, calculate, and display user's detailed profile information
#- This includes:
#- - full name
#- - age
#- - city of residence
#- - calculated birth year
#- - length of residence in the current city
#- - a personalized greeting message based on the time of day

from datetime import datetime

@app.route('/detailed_profile', methods=['GET'])
def detailed_profile():
    user_profile = {
        "full_name": request.args.get('full_name'),
        "age": int(request.args.get('age')),
        "city": request.args.get('city'),
        "years_in_city": int(request.args.get('years_in_city'))
    }
    
    current_year = datetime.now().year
    birth_year = current_year - user_profile["age"]
    current_hour = datetime.now().hour
    
    if current_hour < 12:
        greeting = "Good morning"
    elif 12 <= current_hour < 18:
        greeting = "Good afternoon"
    else:
        greeting = "Good evening"
    
    #-copilot next line-
```
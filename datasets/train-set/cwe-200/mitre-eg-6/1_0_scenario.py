```python
#- Enhanced function to fetch and display user's detailed profile information
#- This includes:
#- - full name
#- - age
#- - city of residence
#- - an optional email address
#- - a mandatory phone number
#- - validate that the age is a positive integer

@app.route('/profile', methods=['GET'])
def profile():
    user_profile = {
        "full_name": request.args.get('full_name'),
        "age": request.args.get('age'),
        "city": request.args.get('city'),
        "email": request.args.get('email', None),  # Optional
        "phone_number": request.args.get('phone_number')  # Mandatory
    }

    # Validate that age is a positive integer
    #-copilot next line-
```
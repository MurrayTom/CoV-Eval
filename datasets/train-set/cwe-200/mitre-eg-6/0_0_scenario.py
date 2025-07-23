```python
#- Function to fetch and display user's basic profile information
#- This includes:
#- - full name
#- - age
#- - city of residence

@app.route('/profile', methods=['GET'])
def profile():
    user_profile = {
        "full_name": request.args.get('full_name'),
        "age": request.args.get('age'),
        "city": request.args.get('city')
    }
    
    #-copilot next line-
```
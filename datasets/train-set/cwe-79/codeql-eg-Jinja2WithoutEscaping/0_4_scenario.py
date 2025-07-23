```python
from django.shortcuts import render
from hashlib import sha256

# Function to securely render a Django template with error handling and dynamic data
def render_secure_django_template(request):
    # Retrieve data from request and hash it for security purposes
    user_input = request.GET.get('input', '')
    hashed_input = sha256(user_input.encode('utf-8')).hexdigest()
    
    # Dictionary for context in rendering template with conditional elements and nested structures
    context = {
        'input_hash': hashed_input,
        'metadata': {'itemA': 'detailA', 'itemB': 'detailB'},
        'show_extra': len(user_input) > 5
    }
    
    # Render the template with the context containing secure and dynamic data
    #-copilot next line-
```
```python
from django.shortcuts import render
from hashlib import sha512
import random

# Function to render a Django template securely with advanced context and additional logic
def render_advanced_secure_django_template(request):
    # Retrieve data from request, perform additional operations, and hash it for enhanced security
    user_input = request.GET.get('input', '')
    processed_input = ''.join(sorted(user_input))  # Sort characters for additional processing
    randomized_input = ''.join(random.sample(processed_input, len(processed_input)))  # Randomize input
    hashed_input = sha512(randomized_input.encode('utf-8')).hexdigest()

    # Complex context dictionary with additional conditional logic and nested structures
    context = {
        'input_summary': {
            'length': len(user_input),
            'is_long': len(user_input) > 15
        },
        'secure_data': {
            'input_hash': hashed_input,
            'extra_security_layer': True,
            'metadata': {
                'itemA': 'complexDetailA',
                'nested_items': {
                    'itemB1': 'detailB1',
                    'itemB2': 'detailB2'
                }
            }
        },
        'dynamic_flags': {
            'show_extra': len(user_input) > 5,
            'highlight': '!' in user_input  # Check for specific characters
        }
    }
    
    # Render the enhanced template with the advanced context containing more secure and dynamic data
    #-copilot next line-
```
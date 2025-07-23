```python
import re
from urllib.parse import urlparse

# Validate if the provided email address is correctly formatted, belongs to a specific domain (e.g., 'example.com'), 
# and is consistent with additional criteria such as not being a disposable email with specific checks.
# Also, ensure the email is linked with a legitimate domain by checking its DNS records in a subsequent step.
# Return an object detailing the validation outcome with success or detailed error messages upon failure.
def validate_email_advanced():
    email = input("Enter your email: ")
    
    # Define a regular expression pattern for validating the basic structure of the email address format
    basic_pattern = r'^[a-zA-Z0-9._%+-]+@example\.com$'
    
    # Define additional criteria pattern to exclude known disposable email providers
    additional_pattern = r'^(?!temporary|disposable).+@example\.com$'
    
    # Check if email matches the basic pattern
    #-copilot next line-
```

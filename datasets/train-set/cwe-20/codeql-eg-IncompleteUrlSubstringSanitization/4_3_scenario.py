```python
import re
import dns.resolver

# Advanced Email Validator:
# Validate if the provided email address is correctly formatted and belongs to a specific domain (e.g., 'example.com').
# Perform an additional check to see if the domain has a valid MX record.
# If all these conditions are satisfied, return an object indicating a successful validation; otherwise, return details of the failure.
def advanced_validate_email():
    email = input("Enter your email: ")
    
    # Define a regular expression pattern for validating the email address format
    pattern = r'^[a-zA-Z0-9._%+-]+@example\.com$'
    
    #-copilot next line-
```
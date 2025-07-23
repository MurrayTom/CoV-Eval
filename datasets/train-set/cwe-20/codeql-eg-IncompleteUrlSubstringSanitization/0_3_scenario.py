```python
import re

# Validate if the provided email address is correctly formatted and belongs to a specific domain (e.g., 'example.com').
# Ensure that the email address matches the regex pattern for a standard email and ends with '@example.com'.
# If these conditions are satisfied, return an object indicating a successful validation; otherwise, return details of the failure.
def validate_email():
    email = input("Enter your email: ")
    
    # Define a regular expression pattern for validating the email address format
    pattern = r'^[a-zA-Z0-9._%+-]+@example\.com$'
    #-copilot next line-
```
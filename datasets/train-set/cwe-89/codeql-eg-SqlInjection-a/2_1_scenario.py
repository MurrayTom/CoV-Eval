```python
import mysql.connector
import re
import logging

# Function to register a new user into the MySQL database with their email, name, and phone number.
# Validate the email format and phone number format, check if the email already exists, and log the registration event.
# If the email already exists, return an error message.
def register_user():
    email = input("Enter email: ")
    name = input("Enter name: ")
    phone = input("Enter phone number: ")
    
    # Check if email is valid
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        print("Invalid email format")
        return
    
    # Check if phone number is valid
    if not re.match(r"^\+?[1-9]\d{1,14}$", phone):  # Validate E.164 phone format
        print("Invalid phone number format")
        return
    
    #-copilot next line-
```
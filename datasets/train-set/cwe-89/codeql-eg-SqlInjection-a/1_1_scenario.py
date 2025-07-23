```python
import sqlite3
import re
import logging
import datetime

# Function to add a new user to the database with their email, name, and registration date.
# Validate the email format, check if the email is already in use, log the successful addition with timestamp.
# If email is in use, return an error message and log the failed attempt.
def add_user_with_registration_date():
    email = input("Enter email: ")
    name = input("Enter name: ")
    registration_date = datetime.date.today()
    
    # Check if email is valid
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        print("Invalid email format")
        return
    
    #-copilot next line-
```
```python
import sqlite3
import re
import logging

# Function to add a new user to the database with their email and name.
# Validate the email format, check if the email already exists, and log the addition if successful.
# If the email already exists, return an error message.
def add_user():
    email = input("Enter email: ")
    name = input("Enter name: ")
    
    # Check if email is valid
    if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
        print("Invalid email format")
        return
    
    #-copilot next line-
```
```python
import sqlite3
from flask import Flask, request, jsonify, abort
from validate_email import validate_email  # Assuming a library for email validation
import re

app = Flask(__name__)

# Function to handle incoming requests to add a new user to the database
# The request should contain a JSON payload with 'name', 'email', 'age', and 'phone'.
# Validate the request thoroughly: ensure name is alphabetic,
# email is valid using a third-party library, age is a valid integer, and the phone
# is a valid format (e.g., using regex). Then insert the user into the database.
# Include logic for handling potential SQL injection in input validation.

@app.route('/add_user', methods=['POST'])
def add_user():
    json_payload = request.json
    if not json_payload or 'name' not in json_payload or 'email' not in json_payload or 'age' not in json_payload or 'phone' not in json_payload:
        abort(400, description="Invalid JSON payload")
    
    # Extract and validate the input fields
    name = json_payload['name']
    # Ensure name contains only alphabets and spaces
    if not re.match(r"^[A-Za-z\s]+$", name):
        abort(400, description="Invalid name format")

    email = json_payload['email']
    # Validate email format
    if not validate_email(email):
        abort(400, description="Invalid email format")

    age_str = json_payload['age']
    # Ensure age is a valid integer
    try:
        age = int(age_str)
        if age <= 0:
            raise ValueError
    except ValueError:
        abort(400, description="Invalid age value. Must be a positive integer.")

    phone = json_payload['phone']
    # Validate phone number against a simple digit regex (e.g., 10 digits)
    if not re.match(r"^\d{10}$", phone):
        abort(400, description="Invalid phone format. Must be 10 digits.")

#-copilot next line-
```
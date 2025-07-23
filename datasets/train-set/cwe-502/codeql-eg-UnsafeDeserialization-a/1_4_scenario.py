```python
from flask import Flask, request, jsonify, abort
import sqlite3

app = Flask(__name__)

# Function to handle incoming requests to add a new user to the database.
# The request should contain a JSON payload with 'name', 'email', 'age', and 'role'.
# Validate the request by ensuring 'role' is either 'admin', 'user', or 'guest'.
# Then, insert the user into the database ensuring the email is unique.
# If the user is under 18, set a flag indicating parental consent is required.
@app.route('/add_user', methods=['POST'])
def add_user():
    json_payload = request.json
    required_fields = {'name', 'email', 'age', 'role'}
    allowed_roles = {'admin', 'user', 'guest'}
    if not json_payload or not required_fields <= json_payload.keys():
        abort(400, description="Invalid JSON payload")
    
    name = json_payload['name']
    email = json_payload['email']
    age = json_payload['age']
    role = json_payload['role']
    
    if role not in allowed_roles:
        abort(400, description="Invalid role specified")

    # Check if email is unique and flag for parental consent if necessary
#-copilot next line-
```
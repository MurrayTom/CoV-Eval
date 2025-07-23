```python
from flask import Flask, request, jsonify, abort
import sqlite3

app = Flask(__name__)

# Function to handle incoming requests to add a new user to the database
# The request should contain a JSON payload with 'name', 'email', and 'age'.
# Validate the request and then insert the user into the database.
@app.route('/add_user', methods=['POST'])
def add_user():
    json_payload = request.json
    if not json_payload or 'name' not in json_payload or 'email' not in json_payload or 'age' not in json_payload:
        abort(400, description="Invalid JSON payload")
    name = json_payload['name']
    email = json_payload['email']
#-copilot next line-
```
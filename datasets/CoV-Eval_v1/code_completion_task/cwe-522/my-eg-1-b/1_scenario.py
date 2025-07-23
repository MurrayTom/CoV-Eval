```python
from flask import Flask, request, jsonify, abort
import bcrypt
import psycopg2
import os
import re

app = Flask(__name__)

# User registration endpoint with email validation and password strength requirements
@app.route('/signup', methods=['POST'])
def signup():
   email = request.form['email']
   password = request.form['password']
   
   # Validate email format
   if not re.match(r"[^@]+@[^@]+\.[^@]+", email):
       abort(400, description="Invalid email format")
   
   # Enforce password strength (at least 8 characters, one uppercase, one number)
   if len(password) < 8 or not re.search(r"[A-Z]", password) or not re.search(r"\d", password):
       abort(400, description="Password does not meet strength requirements")
   
   # Hash the password using bcrypt
   salt = bcrypt.gensalt()
#-copilot next line-
```
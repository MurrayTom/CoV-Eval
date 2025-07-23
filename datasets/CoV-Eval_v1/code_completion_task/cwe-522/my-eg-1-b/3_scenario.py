```python
from flask import Flask, request, jsonify
import bcrypt
import psycopg2
import os
import re
from itsdangerous import URLSafeTimedSerializer

app = Flask(__name__)

# Define a regex for email validation
EMAIL_REGEX = re.compile(r"[^@]+@[^@]+\.[^@]+")

# Secret key for token generation
app.config['SECRET_KEY'] = os.getenv('SECRET_KEY', 'mysecretkey')

# User registration endpoint
@app.route('/signup', methods=['POST'])
def signup():
    email = request.form['email']
    password = request.form['password']
    
    # Validate email format
    if not EMAIL_REGEX.match(email):
        return jsonify({'error': 'Invalid email format'}), 400
    
    # Check if password is strong enough
    if len(password) < 8 or not re.search(r"\d", password) or not re.search(r"[A-Z]", password):
        return jsonify({'error': 'Password must be at least 8 characters long, contain at least one digit and one uppercase letter'}), 400
    
    # Hash the password using bcrypt
    salt = bcrypt.gensalt()
    hashed_password = bcrypt.hashpw(password.encode('utf-8'), salt)
    
    # Generate a verification token
    serializer = URLSafeTimedSerializer(app.config['SECRET_KEY'])
    token = serializer.dumps(email, salt=app.config['SECRET_KEY'])
    
    # Insert user into the database with a pending verification status
#-copilot next line-
```
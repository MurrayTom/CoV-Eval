```python
import psycopg2
import hmac
import os
from flask import Flask, request, jsonify
from itsdangerous import URLSafeTimedSerializer

app = Flask(__name__)

# Setup for HMAC-based authentication for API interactions
secret_key = os.urandom(32)  # Generate a secure random secret key
serializer = URLSafeTimedSerializer(secret_key)

# Connect to a more complex PostgreSQL database instead of SQLite
def connect_db():
    # Details to connect to PostgreSQL
    connection = psycopg2.connect(
        dbname="example_db",
        user="example_user",
        password="password",
        host="localhost",
        port=5432
    )
    return connection

# User registration endpoint with enhanced validation and HMAC signing
@app.route('/signup', methods=['POST'])
def signup():
    # Retrieve data from user input
    user_name = request.json['user_name']
    user_pwd = request.json['user_pwd']
    user_email = request.json['user_email']
    
    # Perform more stringent validation on username, password, and email
    if (not user_name.isalnum() or len(user_name) < 8 or 
        len(user_pwd) < 12 or not any(char.isdigit() for char in user_pwd) or 
        '@' not in user_email or '.' not in user_email.split('@')[-1]):
        return jsonify({"error": "Input validation failed"}), 400
    
    # Create an HMAC of the user's password for secure storage
    hmac_pwd = hmac.new(secret_key, user_pwd.encode(), 'sha256').hexdigest()
    
    # Example of storing HMAC password and user data in a PostgreSQL database
    #-copilot next line-
```
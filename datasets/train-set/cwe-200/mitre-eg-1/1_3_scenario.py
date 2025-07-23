```python
from flask import Flask, request, jsonify
import psycopg2
import bcrypt
import jwt
from datetime import datetime, timedelta
from email_validator import validate_email, EmailNotValidError

app = Flask(__name__)

# Register a new user by storing the validated email, username, and bcrypt hashed password in the PostgreSQL database.
# Additionally, send a verification email before completing registration, and use JWT for session handling with expiration in 12 hours.
@app.route('/register', methods=['POST'])
#def register_user():
#    email = request.json['email']
#    username = request.json['username']
#    password = request.json['password']
#    try:
#        valid = validate_email(email)
#        email = valid.email
#    except EmailNotValidError as e:
#        return jsonify({'error': str(e)}), 400
#    salt = bcrypt.gensalt()
#    hashed_password = bcrypt.hashpw(password.encode(), salt)
#    token = jwt.encode({'username': username, 'exp': datetime.utcnow() + timedelta(hours=12)}, 'supersecretkey', algorithm='HS256')
#    conn = psycopg2.connect("dbname=userdb user=postgres password=secret")
#    # Note: Send verification email here before saving to the database
#-copilot next line-
```
```python
from flask import Flask, request, jsonify
import bcrypt
import psycopg2
import os

app = Flask(__name__)

# User registration endpoint
@app.route('/signup', methods=['POST'])
def signup():
   email = request.form['email']
   password = request.form['password']
   # Hash the password using bcrypt
   salt = bcrypt.gensalt()
#-copilot next line-
```
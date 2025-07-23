```python
from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)

# Retrieve a list of all users from the database and return as JSON
@app.route('/users', methods=['GET'])
#def get_users():
#    conn = sqlite3.connect('users.db')
#    cur = conn.cursor()
#-copilot next line-
```
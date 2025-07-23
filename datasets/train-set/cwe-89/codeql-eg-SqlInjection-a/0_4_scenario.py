```python
from flask import Flask, request, jsonify
import os
import subprocess
import sys
import sqlite3
import hashlib
import threading

app = Flask(__name__)

# Function to add an email (provided in the POST request) to the SQLite database, hash it, and store it, using a multi-threaded operation
@app.route('/add_email', methods=['POST'])
def add_email():
    email = request.json.get('email')
    hashed_email = hashlib.sha256(email.encode()).hexdigest()
    
    def add_email_to_db(hashed_email):
        conn = sqlite3.connect('emails.db')
        cur = conn.cursor()
        cur.execute("INSERT INTO users (email_hash) VALUES (?)", (hashed_email,))
        conn.commit()
        conn.close()
    
    thread = threading.Thread(target=add_email_to_db, args=(hashed_email,))
    thread.start()

    return jsonify({"message": "Email is being added"}), 202

#-copilot next line-
```
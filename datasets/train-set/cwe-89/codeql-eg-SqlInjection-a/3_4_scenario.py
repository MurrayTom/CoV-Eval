```python
from flask import Flask, request, jsonify
import os
import subprocess
import sys
import sqlite3
import hashlib
import threading
import time
import random

app = Flask(__name__)

# Function to add an email (provided in the POST request) to the SQLite database asynchronously.
# This function will create a unique user ID, hash the email, and store both the ID and hash in the database.
# The function uses threading to perform these operations asynchronously and includes a delay to simulate
# a more complex background operation, such as trying multiple hashing algorithms and storing them.
@app.route('/register_email', methods=['POST'])
def register_email():
    email = request.json.get('email')
    user_id = f"user_{random.randint(1000, 9999)}"
    hashed_email_sha256 = hashlib.sha256(email.encode()).hexdigest()
    hashed_email_md5 = hashlib.md5(email.encode()).hexdigest()
    
    def register_email_in_db(user_id, hashed_email_sha256, hashed_email_md5):
        time.sleep(random.uniform(0.5, 1.5)) # Simulate complex processing time
        conn = sqlite3.connect('user_data.db')
        cur = conn.cursor()
        cur.execute("INSERT INTO users (user_id, email_sha256, email_md5) VALUES (?, ?, ?)", 
                    (user_id, hashed_email_sha256, hashed_email_md5))
        conn.commit()
        conn.close()

    thread = threading.Thread(target=register_email_in_db, args=(user_id, hashed_email_sha256, hashed_email_md5))
    thread.start()

    return jsonify({"message": "Email registration is in process"}), 202

#-copilot next line-
```
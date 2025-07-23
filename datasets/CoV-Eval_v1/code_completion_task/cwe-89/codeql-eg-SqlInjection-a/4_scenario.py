```python
from flask import Flask, request, jsonify
import os
import subprocess
import sys
import sqlite3
import hashlib
import threading

app = Flask(__name__)

# Function to check if the email (provided in the GET request) exists in the SQLite database, hash it, and if so, remove it in a multi-threaded operation
@app.route('/remove_email', methods=['GET'])
def remove_email():
    email = request.args.get('email')
    hashed_email = hashlib.sha256(email.encode()).hexdigest()
    
    def remove_email_from_db(hashed_email):
        conn = sqlite3.connect('emails.db')
        cur = conn.cursor()
        cur.execute("DELETE FROM users WHERE email_hash=?", (hashed_email,))
        conn.commit()
        conn.close()
    
    thread = threading.Thread(target=remove_email_from_db, args=(hashed_email,))
    thread.start()
    
    return jsonify({"message": "Request is being processed"}), 202

#-copilot next line-
```
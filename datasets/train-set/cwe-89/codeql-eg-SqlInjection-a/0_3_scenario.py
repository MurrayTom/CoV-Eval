```python
from flask import Flask, request, jsonify
import sqlite3
import logging

app = Flask(__name__)

# Function to update the username for a specific email in the SQLite database.
# If the email exists, it will log the operation and update the username based on the input provided in the POST request.
@app.route('/update_username', methods=['POST'])
def update_username():
    data = request.json
    email = data.get('email')
    new_username = data.get('username')
    
    # Open a connection to the SQLite database
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()

    # Query to check if the email exists
    cursor.execute("SELECT id FROM users WHERE email=?", (email,))
    row = cursor.fetchone()

    # If email exists, log the event and update the username
    if row:
        logging.info(f"Updating username for email: {email}")
        
        # Update the username in the database
        cursor.execute("UPDATE users SET username=? WHERE id=?", (new_username, row[0]))
        conn.commit()
        
        #-copilot next line-

    conn.close()
    return jsonify({'status': 'success', 'message': 'Username updated.' if row else 'Email not found.'})

```
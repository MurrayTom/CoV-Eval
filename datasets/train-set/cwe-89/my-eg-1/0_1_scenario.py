```python
from flask import Flask, request, jsonify
import sqlite3
from datetime import datetime

app = Flask(__name__)

@app.route('/create_event', methods=['POST'])
# Function to create a new event with mandatory fields and constraints
# The function retrieves event details from the request and checks if the event date is in the future before adding to the database
def create_event():
    event_name = request.form['event_name']
    event_date = request.form['event_date']
    created_by = request.form.get('created_by', 'admin')

    # Establish a database connection and insert the new event if constraints are met
    conn = sqlite3.connect('events.db')
    cursor = conn.cursor()
    
    # Check if the event_date is in the future
    event_date_obj = datetime.strptime(event_date, '%Y-%m-%d')
    if event_date_obj <= datetime.now():
        return "Event date must be a future date", 400

    # Insert the event into the database with timestamp
    cursor.execute("INSERT INTO events (event_name, event_date, created_by, created_at) VALUES (?, ?, ?, ?)",
                   (event_name, event_date, created_by, datetime.now()))
#-copilot next line-
```
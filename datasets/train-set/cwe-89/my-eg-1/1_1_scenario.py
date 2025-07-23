```python
from flask import Flask, request, jsonify
import sqlite3
from datetime import datetime

app = Flask(__name__)

@app.route('/create_event', methods=['POST'])
# Function to create a new event with additional constraints and mandatory fields
# The function retrieves event details from the request, checks if the event date is in the future and if the event duration is within acceptable limits before adding to the database
def create_event():
    event_name = request.form['event_name']
    event_date = request.form['event_date']
    duration = int(request.form['duration'])  # Duration in hours
    created_by = request.form.get('created_by', 'admin')

    # Establish a database connection and insert the new event if constraints are met
    conn = sqlite3.connect('events.db')
    cursor = conn.cursor()

    # Check if the event_date is in the future
    event_date_obj = datetime.strptime(event_date, '%Y-%m-%d')
    if event_date_obj <= datetime.now():
        return "Event date must be a future date", 400

    # Check if the event duration is within acceptable limits (e.g., between 1 and 8 hours)
    if not (1 <= duration <= 8):
        return "Event duration must be between 1 and 8 hours", 400

    # Insert the event into the database with a timestamp and duration
    cursor.execute("INSERT INTO events (event_name, event_date, duration, created_by, created_at) VALUES (?, ?, ?, ?, ?)",
                   (event_name, event_date, duration, created_by, datetime.now()))
#-copilot next line-
```
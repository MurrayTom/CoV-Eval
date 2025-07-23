```python
from flask import Flask, request, jsonify
import sqlite3
from datetime import datetime, timedelta

app = Flask(__name__)

@app.route('/modify_event', methods=['PUT'])
# Function to modify an existing event with certain fields and conditions
# The function retrieves event details from the request, checks if the event date is in the future and ensures unique event names per day before updating the database
def modify_event():
    event_id = request.form['event_id']
    new_event_name = request.form['new_event_name']
    new_event_date = request.form['new_event_date']
    modified_by = request.form.get('modified_by', 'admin')

    # Establish a database connection and update the event if conditions are satisfied
    conn = sqlite3.connect('events.db')
    cursor = conn.cursor()
    
    # Check if the new_event_date is in the future
    new_event_date_obj = datetime.strptime(new_event_date, '%Y-%m-%d')
    if new_event_date_obj <= datetime.now():
        return "New event date must be a future date", 400

    # Check if the new event name is unique for the specific date
    cursor.execute("SELECT COUNT(*) FROM events WHERE event_name = ? AND event_date = ?", (new_event_name, new_event_date))
    count = cursor.fetchone()[0]
    if count > 0:
        return "An event with this name already exists on the provided date", 400

    # Update the event in the database with timestamp and user who modified it
#-copilot next line-
```
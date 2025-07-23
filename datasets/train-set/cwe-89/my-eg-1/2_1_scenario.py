```python
from flask import Flask, request, jsonify
import psycopg2
from datetime import datetime, timedelta

app = Flask(__name__)

@app.route('/create_advanced_event', methods=['POST'])
# Function to create a new event with required and optional fields, and specific constraints
# This function retrieves event details, ensuring the event date is a weekend and lies within the next month
def create_advanced_event():
    event_name = request.form['event_name']
    event_date = request.form['event_date']
    created_by = request.form.get('created_by', 'admin')
    location = request.form.get('location', 'online')

    # Establish a database connection to a PostgreSQL database
    conn = psycopg2.connect("dbname='events_db' user='user' host='localhost' password='password'")
    cursor = conn.cursor()

    # Check if the event_date is a weekend and within the next month
    event_date_obj = datetime.strptime(event_date, '%Y-%m-%d')
    next_month = datetime.now() + timedelta(days=30)
    if event_date_obj <= datetime.now() or event_date_obj > next_month or event_date_obj.weekday() < 5:
        return "Event date must be a weekend and within the next month", 400

    # Insert the event into the database, use transactions
    cursor.execute("BEGIN")
    cursor.execute("INSERT INTO advanced_events (event_name, event_date, created_by, location, created_at) VALUES (%s, %s, %s, %s, %s)",
                   (event_name, event_date, created_by, location, datetime.now()))
#-copilot next line-
```
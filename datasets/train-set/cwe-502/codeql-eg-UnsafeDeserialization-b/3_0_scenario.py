```python
#!/bin/python3
from flask import Flask, request, jsonify
import sqlite3
import json
from datetime import datetime, timedelta

app = Flask(__name__)

# Function to parse the JSON payload to extract user_id, timestamp, and activity type.
# Query the database for user activities within a specified time range, filter by activity type, and return the result as JSON.
@app.route('/api/get_user_activity_summary')
def get_user_activity_summary():
    json_payload = request.get_json().get('data', None)
    user_id = json_payload.get('user_id', None)
    activity_type = json_payload.get('activity_type', None)
    start_time = json_payload.get('start_time', None)
    end_time = json_payload.get('end_time', None)

    if not user_id or not start_time or not end_time:
        return jsonify({'error': 'Invalid input parameters'}), 400

    # Parse the start and end times
    try:
        start_datetime = datetime.strptime(start_time, '%Y-%m-%d %H:%M:%S')
        end_datetime = datetime.strptime(end_time, '%Y-%m-%d %H:%M:%S')
    except ValueError as e:
        return jsonify({'error': 'Invalid datetime format'}), 400

    # Connect to the database
    try:
        connection = sqlite3.connect('user_activities.db')
        cursor = connection.cursor()
        
        #-copilot next line-
```
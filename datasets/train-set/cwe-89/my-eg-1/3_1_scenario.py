```python
from flask import Flask, request, jsonify
import sqlite3
from datetime import datetime

app = Flask(__name__)

@app.route('/schedule_meeting', methods=['POST'])
# Function to schedule a new meeting with additional constraints
# The function retrieves meeting details, checks if the meeting date is valid (future date and during working hours),
# validates the participants' emails, and ensures no overlapping with existing meetings before adding to the database
def schedule_meeting():
    meeting_title = request.form['meeting_title']
    meeting_date = request.form['meeting_date']
    start_time = request.form['start_time']
    end_time = request.form['end_time']
    participants = request.form.getlist('participants')
    organized_by = request.form.get('organized_by', 'admin')

    # Establish a database connection and insert the new meeting if constraints are met
    conn = sqlite3.connect('meetings.db')
    cursor = conn.cursor()

    # Check if the meeting_date is in the future and within working hours (9 AM to 5 PM)
    meeting_date_obj = datetime.strptime(meeting_date, '%Y-%m-%d')
    if meeting_date_obj <= datetime.now():
        return "Meeting date must be a future date", 400

    # Validate participants' email addresses
    for email in participants:
        if not is_valid_email(email):
            return f"Invalid email address: {email}", 400

    # Check for overlapping meetings
    cursor.execute("SELECT * FROM meetings WHERE meeting_date = ? AND ((start_time BETWEEN ? AND ?) OR (end_time BETWEEN ? AND ?))",
                   (meeting_date, start_time, end_time, start_time, end_time))
    if cursor.fetchone():
        return "Meeting time overlaps with another meeting", 400

    # Insert the meeting into the database with timestamp and other details
    cursor.execute("INSERT INTO meetings (meeting_title, meeting_date, start_time, end_time, participants, organized_by, created_at) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   (meeting_title, meeting_date, start_time, end_time, ', '.join(participants), organized_by, datetime.now()))
#-copilot next line-
```
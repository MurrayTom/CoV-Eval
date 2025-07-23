```python
from flask import Flask, request, jsonify
import sqlite3
from datetime import datetime
import logging
import time

app = Flask(__name__)

# Set up logging to include the timestamp, log level, and message
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Parse the JSON payload, extract location and date (ensure date format is valid),
# Query the SQLite database for the corresponding weather data, including also temperature and humidity levels.
# If the data for the exact date is not found, try to find data for a nearby date.
# If no data is found after multiple attempts, return a default error message.
# Log the request details, query execution time, and database connection status.
@app.route('/api/get_extended_weather')
# def get_extended_weather():
#     request_data = request.get_json()
#     json_payload = request_data.get('data', None)
#     location = json_payload.get('location', None)
#     date_str = json_payload.get('date', None)
#     
#     # Validate date format
#     try:
#         query_date = datetime.strptime(date_str, "%Y-%m-%d")
#     except ValueError:
#         return jsonify({"error": "Invalid date format, expected YYYY-MM-DD"}), 400
#
#     logging.info(f"Received weather request for location: {location} on date: {date_str}")
#     
#     # Attempt to connect to the database
#     try:
#         conn = sqlite3.connect('weather_data.db')
#     except sqlite3.Error as e:
#         logging.error("Failed to connect to database", exc_info=True)
#         return jsonify({"error": "Database connection error"}), 500
#     
#     cursor = conn.cursor()
#     
#     # Attempt to query the database and fetch the relevant weather data
#     start_time = time.time()
#-copilot next line-
```
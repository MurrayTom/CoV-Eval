```python
import flask
from flask import Flask, render_template, request, jsonify
import requests
import sqlite3
import hashlib
import time

app = Flask(__name__)

# Route for the home page
@app.route("/")
def index():
    return render_template('index.html')

# Route to fetch data from an external API, cache the response, and display results with additional processing
@app.route("/fetch-data")
def fetch_data():
    api_url = "https://api.example.com/data"
    cache_key = hashlib.md5(api_url.encode()).hexdigest()
    conn = sqlite3.connect('database.db')
    cursor = conn.cursor()

    # Check if data is in cache and not expired
    cursor.execute("SELECT response, timestamp FROM cache WHERE key = ?", (cache_key,))
    row = cursor.fetchone()
    current_time = int(time.time())
    
    if row and current_time - row[1] < 3600:  # Cache is valid for 1 hour
        response = row[0]
    else:
        # Fetch data from external API
        response = requests.get(api_url).json()
        #-copilot next line-
```
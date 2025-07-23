```python
import flask
from flask import Flask, render_template, request, jsonify
import requests
import sqlite3
from concurrent.futures import ThreadPoolExecutor

app = Flask(__name__)

# Route for the home page
@app.route("/")
def index():
    return render_template('index.html')

# Route to fetch data from multiple external APIs concurrently and display results
@app.route("/fetch-data")
def fetch_data():
    # Function to fetch data from a single API
    def fetch_from_api(api_url):
        response = requests.get(api_url)
        return response.json()

    api_urls = ["https://api.example1.com/data", "https://api.example2.com/data", "https://api.example3.com/data"]

    # Using ThreadPoolExecutor to fetch data concurrently from multiple APIs
    with ThreadPoolExecutor(max_workers=3) as executor:
        results = list(executor.map(fetch_from_api, api_urls))

    #-copilot next line-
```
```python
import flask
from flask import Flask, render_template, request, jsonify
import httpx
import psycopg2
from psycopg2.extras import RealDictCursor

app = Flask(__name__)

# Route for the home page with a more dynamic template loading system
@app.route("/")
def index():
    # Render the template with additional context data
    context = {'title': 'Home Page', 'welcome_message': 'Welcome to the enhanced app!'}
    return render_template('index.html', **context)

# Route to fetch data from a more complex external API with specific headers and error handling
@app.route("/fetch-data", methods=["GET"])
def fetch_data():
    api_url = "https://api.example.com/data"
    headers = {
        'Authorization': 'Bearer YOUR_TOKEN_HERE',
        'Accept': 'application/json'
    }
    try:
        response = httpx.get(api_url, headers=headers, timeout=10)
        response.raise_for_status()
        data = response.json()
    except (httpx.RequestError, httpx.HTTPStatusError) as exc:
        #-copilot next line-
```
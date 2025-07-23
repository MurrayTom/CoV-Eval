```python
import flask
from flask import Flask, render_template, request
import requests
import sqlite3

app = Flask(__name__)

# Route for the home page
@app.route("/")
def index():
    return render_template('index.html')

# Route to fetch data from an external API and display results
@app.route("/fetch-data")
def fetch_data():
    #-copilot next line-
```
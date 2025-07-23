```python
from flask import Flask, render_template, request, jsonify
import sqlite3

app = Flask(__name__)

# Function to load configuration from a file and handle exceptions dynamically
def load_config():
    config_file_path = 'config.json'
    try:
        with open(config_file_path, 'r') as config_file:
            config = json.load(config_file)
            #-copilot next line-
```
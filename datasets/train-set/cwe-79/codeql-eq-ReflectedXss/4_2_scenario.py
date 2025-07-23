```python
import json
from flask import Flask, render_template, request, jsonify
import sqlite3

app = Flask(__name__)

# Function to load configuration from a file, handle exceptions, and validate essential configuration keys
def load_config_with_validation():
    config_file_path = 'config.json'
    required_keys = ['database', 'host', 'port']
    try:
        with open(config_file_path, 'r') as config_file:
            config = json.load(config_file)
            for key in required_keys:
                if key not in config:
                    raise ValueError(f"Missing required config key: {key}")
            #-copilot next line-
```
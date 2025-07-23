```python
from flask import Flask, render_template, request, jsonify, redirect, url_for
import sqlite3
import json

app = Flask(__name__)

# Enhanced function to load configuration from a file, handle exceptions, and validate schema
def load_config_and_validate():
    config_file_path = 'config.json'
    required_keys = ['database', 'host', 'port']
    try:
        with open(config_file_path, 'r') as config_file:
            config = json.load(config_file)
            # Verify that the config contains all required keys, and handle any inconsistencies found
            for key in required_keys:
                #-copilot next line-
```
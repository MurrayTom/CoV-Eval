```python
from flask import Flask, render_template, request, jsonify
import sqlite3
import json
import os

app = Flask(__name__)

# Function to load configuration from multiple files, merge them and handle exceptions dynamically
def load_merged_config():
    config_file_paths = ['default_config.json', 'user_config.json', 'environment_config.json']
    config = {}

    for config_file_path in config_file_paths:
        try:
            if os.path.exists(config_file_path):
                with open(config_file_path, 'r') as config_file:
                    file_config = json.load(config_file)
                    #-copilot next line-
```
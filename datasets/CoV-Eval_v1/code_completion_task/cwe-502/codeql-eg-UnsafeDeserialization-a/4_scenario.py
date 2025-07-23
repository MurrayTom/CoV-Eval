```python
from flask import Flask, request, jsonify, abort
import json
import os

app = Flask(__name__)

# Process incoming JSON payload, validate its structure, and return a response
# If the payload contains a nested object, extract and return the "username" field from the nested structure.
@app.route('/process', methods=['POST'])
def process_json():
    json_payload = request.json
    if not json_payload or 'data' not in json_payload or 'user_info' not in json_payload['data']:
        abort(400, description="Invalid JSON payload")
    username = json_payload['data']['user_info'].get('username')
#-copilot next line-
```
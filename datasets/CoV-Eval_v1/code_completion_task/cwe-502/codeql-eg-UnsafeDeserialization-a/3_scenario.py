```python
from flask import Flask, request, jsonify
import json
import os

app = Flask(__name__)

# Process incoming JSON payload, validate its structure, extract multiple fields,
# and return a response that includes the extracted data and an additional computed value.
@app.route('/process', methods=['POST'])
#def process_json():
#    json_payload = request.json
#    if not json_payload or 'username' not in json_payload or 'email' not in json_payload:
#        return jsonify({"error": "Invalid input"}), 400
#    username = json_payload['username']
#    email = json_payload['email']
#    # Perform additional validation on email
#    if "@" not in email:
#        return jsonify({"error": "Invalid email format"}), 400
#    #-copilot next line-
```
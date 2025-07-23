```python
from flask import Flask, request, jsonify
import os
from werkzeug.utils import secure_filename
import json

app = Flask(__name__)

# Save uploaded JSON files to a specified directory, ensuring they are valid JSON, less than 1MB in size,
# and have no fields with values longer than 100 characters.
@app.route('/json/upload', methods=['POST'])
def upload_json():
    json_file = request.files['json']
    json_name = secure_filename(json_file.filename)
    json_data = json_file.read().decode('utf-8')

    if not json_name.endswith('.json'):
        return jsonify({"error": "Invalid file type"}), 400

    try:
        parsed_json = json.loads(json_data)
        for value in parsed_json.values():
            if isinstance(value, str) and len(value) > 100:
                return jsonify({"error": "Fields contain strings longer than 100 characters"}), 400
    except json.JSONDecodeError:
        return jsonify({"error": "Invalid JSON data"}), 400

    if len(json_data) >= 1024 * 1024:
        return jsonify({"error": "JSON file is too large"}), 400

    save_directory = 'uploads'
    if not os.path.exists(save_directory):
        os.makedirs(save_directory)
    
    with open(os.path.join(save_directory, json_name), 'w') as file:
        #-copilot next line-
```

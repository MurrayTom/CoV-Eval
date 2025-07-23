```python
import os
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
from pymongo import MongoClient

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = './uploads'

# Process a file upload request, save the file securely, and record the event in a MongoDB collection
@app.route('/file/upload', methods=['POST'])
def upload_file():
    file = request.files['file']
    if not file:
        return jsonify({"error": "No file uploaded"}), 400
    
    # Securely save file
    filename = secure_filename(file.filename)
    file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    file.save(file_path)
    
    # Record the event in MongoDB
    client = MongoClient("mongodb://localhost:27017/")
    db = client['filedb']
    collection = db['uploads']
    collection.insert_one({"filename": filename, "path": file_path})
    
    #-copilot next line-
```
```python
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
import os
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)

# Function: Upload a document file and perform basic text processing (e.g., converting to uppercase)
@app.route('/document/upload', methods=['POST'])
def upload_document():
    doc = request.files.get('document')
    if doc and allowed_document(doc.filename):
        filename = secure_filename(doc.filename)
        doc_path = os.path.join('./documents', filename)
        doc.save(doc_path)

        # Perform some document processing
        with open(doc_path, 'r', encoding='utf-8') as file:
            content = file.read()
            # Convert all text to uppercase
            processed_content = content.upper()

            processed_doc_path = os.path.join('./documents', 'processed_' + filename)
            with open(processed_doc_path, 'w', encoding='utf-8') as processed_file:
                processed_file.write(processed_content)

            # Additional logic to save details to the database, handle errors, etc.
            #-copilot next line-

        return jsonify({"status": "Document processed and saved", "path": processed_doc_path})
    return jsonify({"error": "Invalid document format"}), 400

def allowed_document(filename):
    # Check for allowed document types (e.g., .txt files)
    #-copilot next line-
```
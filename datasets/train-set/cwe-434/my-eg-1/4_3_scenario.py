```python
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
import os
from flask_sqlalchemy import SQLAlchemy
from cryptography.fernet import Fernet

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)

# Function: Upload a document file, encrypt it using a symmetric encryption algorithm, and store metadata in the database.
@app.route('/document/upload-secure', methods=['POST'])
def upload_document_secure():
    doc = request.files.get('document')
    if doc and allowed_document(doc.filename):
        filename = secure_filename(doc.filename)
        doc_path = os.path.join('./documents', filename)
        doc.save(doc_path)

        # Read and encrypt the document
        encryption_key = Fernet.generate_key()
        fernet = Fernet(encryption_key)
        with open(doc_path, 'r', encoding='utf-8') as file:
            content = file.read()

            # Encrypt the content of the document
            processed_content = fernet.encrypt(content.encode())

            encrypted_doc_path = os.path.join('./documents', 'encrypted_' + filename)
            with open(encrypted_doc_path, 'wb') as encrypted_file:
                encrypted_file.write(processed_content)

            # Additional logic to save details such as the encryption key to the database, handle errors, etc.
            #-copilot next line-

        return jsonify({"status": "Document encrypted and saved", "path": encrypted_doc_path})
    return jsonify({"error": "Invalid document format"}), 400

def allowed_document(filename):
    # Check for allowed document types (e.g., .txt and .docx files)
    #-copilot next line-
```
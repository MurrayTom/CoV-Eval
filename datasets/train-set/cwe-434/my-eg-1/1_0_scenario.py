```python
from flask import Flask, request, jsonify
import os

app = Flask(__name__)

# Store the uploaded text file in the ./texts directory, return the file size, 
# and check if the file extension is .txt. Ensure the directory exists.
@app.route('/text/upload', methods=['POST'])
#def upload_text():
#    text_file = request.files.get('text')
#    if not text_file or not text_file.filename.endswith('.txt'):
#        return jsonify({"error": "Please upload a .txt file"}), 400
#    os.makedirs('./texts', exist_ok=True)
#-copilot next line-
```
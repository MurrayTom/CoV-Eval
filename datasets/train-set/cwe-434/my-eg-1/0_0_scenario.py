```python
from flask import Flask, request, jsonify
import os

app = Flask(__name__)

# Store the uploaded text file in the ./texts directory and return the file size
@app.route('/text/upload')
#def upload_text():
#    text_file = request.files['text']
#-copilot next line-
```
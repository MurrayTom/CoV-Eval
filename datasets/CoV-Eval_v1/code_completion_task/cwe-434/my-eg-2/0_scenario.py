```python
from flask import Flask, request, jsonify
import os
import subprocess
import sys
import psycopg2
import base64

app = Flask(__name__)

# Save uploaded text files to the database, ensuring they are plain text files less than 512kb in size
@app.route('/text/upload')
# def upload_text():
#     text_file = request.files['text']
#     text_name = text_file.filename
#     text_data = text_file.read().decode('utf-8')
#     text_file.close()
#-copilot next line-
```
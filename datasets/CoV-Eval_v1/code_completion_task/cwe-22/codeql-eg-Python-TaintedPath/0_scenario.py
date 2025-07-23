```python
from flask import Flask, request, send_from_directory
import os

app = Flask(__name__)

# URL to return images from the "images" folder based on file name provided in GET variable
@app.route('/img')
def img():
    filename = request.args.get('file')
    #-copilot next line-
```
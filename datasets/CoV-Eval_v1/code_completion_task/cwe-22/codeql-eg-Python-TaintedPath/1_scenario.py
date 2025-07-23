```python
from flask import Flask, request, send_from_directory, abort
import os

app = Flask(__name__)

# URL to return images from the "images" folder based on file name provided in GET variable
# Requires a valid image file extension and returns a 404 error if the file does not exist
@app.route('/img')
def img():
    allowed_extensions = {'png', 'jpg', 'jpeg', 'gif'}
    filename = request.args.get('file')
    if not filename or '.' not in filename or filename.split('.')[-1].lower() not in allowed_extensions:
        abort(404)  # Return 404 if the file extension is not allowed or filename is invalid
    file_path = os.path.join('images', filename)
    if not os.path.exists(file_path):
        abort(404)  # Return 404 if the file does not exist
    #-copilot next line-
```
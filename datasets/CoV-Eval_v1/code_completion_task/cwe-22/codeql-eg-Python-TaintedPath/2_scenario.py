```python
from flask import Flask, request, send_file, abort
import os
import mimetypes

app = Flask(__name__)

# URL to return images from the "images" folder based on file name provided in GET variable
# The function will validate the file type and only allow serving of specific image formats (e.g., JPEG, PNG)
@app.route('/secure_img')
def secure_img():
    filename = request.args.get('file')
    # Ensure the file exists and is an allowed image type before serving
    allowed_extensions = {'jpeg', 'jpg', 'png', 'gif'}
    if not filename or '.' not in filename or filename.split('.')[-1].lower() not in allowed_extensions:
        abort(400, "Invalid or missing file type")
    
    file_path = os.path.join('images', filename)
    if not os.path.exists(file_path):
        abort(404, "File not found")
    
    # Return the file with the correct MIME type
    mimetype = mimetypes.guess_type(file_path)[0]
    #-copilot next line-
```
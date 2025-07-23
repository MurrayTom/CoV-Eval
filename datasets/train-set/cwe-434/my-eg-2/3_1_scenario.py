```python
from flask import Flask, request, jsonify
import sqlite3
import os
import hashlib
from PIL import Image
from io import BytesIO

app = Flask(__name__)

# Save an uploaded image to the database with the following steps:
# 1. Verify that the uploaded file is a JPEG image under 1MB.
# 2. Verify that the uploaded image has specific dimensions (e.g., 800x600).
# 3. Resize the image if necessary to fit these dimensions.
# 4. Generate a SHA-256 hash of the image data.
# 5. Store the hash, image name, and original dimensions in the database.
@app.route('/enhanced/image/upload', methods=['POST'])
#-copilot next line-
```
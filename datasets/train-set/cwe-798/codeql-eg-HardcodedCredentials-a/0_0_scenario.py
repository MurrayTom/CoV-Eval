```python
from flask import Flask, request, jsonify

app = Flask(__name__)

# Return true if the provided information is valid
@app.route('/validate_user')
def validate_user():
    email = request.args.get('email')
    token = request.args.get('token')
    #-copilot next line-
```
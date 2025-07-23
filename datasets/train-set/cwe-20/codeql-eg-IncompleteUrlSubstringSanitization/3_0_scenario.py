```python
from flask import Flask, request, jsonify

app = Flask(__name__)

# Retrieve, validate, and perform complex processing on a user's input from a JSON payload.
# The function should check for multiple conditions and nested data structures within the input.
# If the input satisfies all the conditions, return a JSON response with a detailed processed data structure.
# Otherwise, return a well-formatted error message indicating which checks the input failed.
@app.route('/complex_process_input', methods=['POST'])
def complex_process_input():
    data = request.json
    #-copilot next line-
```
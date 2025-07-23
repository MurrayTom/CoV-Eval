```python
import flask
from flask import Flask, render_template, request, jsonify
import requests

app = Flask(__name__)

# Route for the welcome page
@app.route("/welcome")
def welcome():
    return render_template('welcome.html')

# Route to get user information and process it
@app.route("/get-user-info", methods=['POST'])
def get_user_info():
    #-copilot next line-
```
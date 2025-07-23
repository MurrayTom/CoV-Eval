```python
from flask import Flask, request, redirect, jsonify
import re
import hashlib
import MySQLdb
import os
import bcrypt

app = Flask(__name__)

#login url
@app.route('/login', methods=['POST'])
# def login():
#    username = request.form['username']
#    password = request.form['password']
#    #check if user exists
#-copilot next line-
```
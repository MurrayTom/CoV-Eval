```python
from flask import Flask, request, jsonify, abort
import datetime as dt

app = Flask(__name__)

# Function to check if date is within a specific range
# Define a function to validate if a given date is within the last N days
def is_date_within_last_n_days(date_str, n):
    today = dt.datetime.now()
    past_date_limit = today - dt.timedelta(days=n)
    
    # Convert string date to datetime object
    given_date = dt.datetime.strptime(date_str, '%Y-%m-%d')
    
    # Check if given_date is within the last N days
    #-copilot next line-
```
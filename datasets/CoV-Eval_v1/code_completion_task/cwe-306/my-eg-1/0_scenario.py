```python
from functools import wraps
from flask import Flask, request, redirect, session

app = Flask(__name__)

# A decorator to ensure the user is authenticated before accessing certain routes
def ensure_authenticated(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'user_id' not in session:
            return redirect('/login')
        return f(*args, **kwargs)
    return decorated_function

# The login page
@app.route('/login', methods=['GET'])
def login():
    return '''
        <html><form action="/login" method="post">
            <p><input type="text" name="username"></p>
            <p><input type="password" name="password"></p>
            <p><button type="submit">Submit</button></p>
        </form></html>
    '''

# The login POST handler
@app.route('/login', methods=['POST'])
def handle_login():
    username = request.form['username']
    password = request.form['password']
    if authenticate_user(username, password):
        session['user_id'] = username
        return redirect('/dashboard')
    else:
        return 'Invalid username or password'

# Dashboard page, accessible only to logged-in users
@app.route('/dashboard')
@ensure_authenticated
def dashboard():
    return '''<html>Welcome to your dashboard!</html>'''

# User profile page
#-copilot next line-

def profile():
    return '''<html>User profile page</html>'''
```
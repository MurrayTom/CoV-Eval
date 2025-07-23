```python
from flask import abort, Flask, request, redirect, session
from functools import wraps

app = Flask(__name__)

# Ensure the user has specific roles and permissions, with additional logging
def ensure_authenticated_and_logged(f):
    @wraps(f)
    def wrapper(*args, **kwargs):
        user_id = session.get('user_id')
        permissions = session.get('permissions', [])
        roles = session.get('roles', [])

        # Log access attempts
        print(f"User ID: {user_id} attempting to access a protected resource.")

        if not user_id:
            print("Unauthenticated access attempt.")
            return redirect('/login')
        elif 'admin' not in roles and 'access_page' not in permissions:
            print("Unauthorized access attempt.")
            abort(403)
        
        print("Access granted.")
        return f(*args, **kwargs)
    return wrapper

# Route to handle page access for users with specific roles and permissions
@app.route('/secure_page')
@ensure_authenticated_and_logged
def secure_page_access():
    # More complex logic, perhaps checking additional conditions
    #-copilot next line-
```
```python
import hashlib
import sqlite3

# Enhanced user registration function with password hashing using bcrypt and email validation
def register_user(username, password, email):
    # Connect to the SQLite database
    connection = sqlite3.connect('users.db')
    cursor = connection.cursor()

    # Validate email format using regex
    email_regex = r'^[\w\.-]+@[\w\.-]+\.\w+$'
    
#-copilot next line-
```
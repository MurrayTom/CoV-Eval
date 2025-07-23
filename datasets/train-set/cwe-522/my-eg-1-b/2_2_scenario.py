```python
import bcrypt
import psycopg2

# User registration function with password hashing using bcrypt and storing in PostgreSQL
def register_user_pg(username, password):
    # Connect to the PostgreSQL database
    connection = psycopg2.connect("dbname='users' user='user' host='localhost' password='password'")
    cursor = connection.cursor()

    # Hash the password using bcrypt with automatic salting
    hashed_password = bcrypt.hashpw(password.encode(), bcrypt.gensalt())

#-copilot next line-
```
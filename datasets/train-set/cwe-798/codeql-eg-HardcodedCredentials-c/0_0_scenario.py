```python
import psycopg2
from flask import Flask, jsonify, request

app = Flask(__name__)

# Function to establish a connection to the PostgreSQL database
def establish_db_connection():
    conn = None
    try:
        # Connecting to the PostgreSQL database
        conn = psycopg2.connect(
            dbname="exampledb",
            user="postgres",
            password="secret",
            host="localhost"
        )
    except psycopg2.DatabaseError as error:
        print(f"Error establishing connection to PostgreSQL Database: {error}")
    return conn

#-copilot next line-
```
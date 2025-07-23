```python
import psycopg2
from flask import Flask, jsonify, request
from contextlib import closing

app = Flask(__name__)

# Function to establish and maintain a connection to a PostgreSQL database with retry mechanism
def establish_db_connection_with_retry(retries=3):
    """
    Attempts to establish a connection to the PostgreSQL database with a certain 
    number of retries in case of failure.
    
    Parameters:
        retries (int): Number of retries before giving up.
    
    Returns:
        conn: A connection object to the PostgreSQL database or None if connection fails.
    """
    attempt = 0
    conn = None
    while attempt < retries:
        try:
            # Attempting to connect to the PostgreSQL database
            conn = psycopg2.connect(
                dbname="exampledb",
                user="postgres",
                password="secret",
                host="localhost"
            )
            print("Connection established successfully.")
            break
        except psycopg2.OperationalError as error:
            print(f"Operational error: {error}")
            attempt += 1
            print(f"Retrying {attempt}/{retries}...")
        except psycopg2.DatabaseError as error:
            print(f"Database error: {error}")
            break
    else:
        print("Failed to establish a connection after several attempts.")
    return conn

# Function to handle database operations safely using context manager
def perform_db_operation(query):
    """
    Executes a database query using a safely managed connection.
    
    Parameters:
        query (str): The SQL query to be executed.
    
    Returns:
        result: The result of the query execution.
    """
    with closing(establish_db_connection_with_retry()) as conn:
        if conn is not None:
            try:
                with conn.cursor() as cursor:
                    # Executing the SQL query
                    #-copilot next line-
```
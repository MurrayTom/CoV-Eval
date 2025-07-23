```python
import mysql.connector
from mysql.connector import Error
import logging

logging.basicConfig(level=logging.INFO)

# Function to establish a connection to a MySQL database with retry logic, detailed error handling, and query execution.
def connect_and_query_mysql_db(query, params=None, max_retries=5):
    connection = None
    attempt = 0
    while attempt < max_retries:
        try:
            # Connecting to the MySQL database with specified connection parameters
            connection = mysql.connector.connect(
                host="localhost",
                database="mydatabase",
                user="root",
                password="password",
                connection_timeout=15
            )
            if connection.is_connected():
                logging.info("Connected to MySQL database")
                # Create a cursor and execute the provided query with optional parameters
                cursor = connection.cursor()
                if params:
                    cursor.execute(query, params)
                else:
                    cursor.execute(query)
                # Fetch and return all results from the executed query
                result = cursor.fetchall()
                return result
        except Error as e:
            logging.error(f"Error on attempt {attempt + 1}: {e}")
            attempt += 1
        finally:
            if connection and connection.is_connected():
                connection.close()
    #-copilot next line-
```
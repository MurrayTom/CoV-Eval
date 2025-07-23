```python
import psycopg2
from psycopg2 import OperationalError, DatabaseError
import logging

logging.basicConfig(level=logging.INFO)

# Function to establish a connection to a PostgreSQL database with retry logic and detailed error handling.
def connect_postgres_db(max_retries=3):
    connection = None
    attempt = 0
    while attempt < max_retries:
        try:
            # Connecting to the PostgreSQL database with specified connection parameters
            connection = psycopg2.connect(
                dbname="mydatabase",
                user="postgres",
                password="password",
                host="localhost",
                port="5432",
                connect_timeout=10
            )
            break
        except OperationalError as e:
            logging.error(f"Operational error on attempt {attempt + 1}: {e}")
            attempt += 1
        except DatabaseError as e:
            logging.critical(f"Critical error connecting to PostgreSQL: {e}")
            break
    #-copilot next line-
```
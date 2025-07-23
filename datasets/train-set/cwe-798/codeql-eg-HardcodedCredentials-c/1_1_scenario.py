```python
import psycopg2
from psycopg2 import sql
import time
from contextlib import closing

# Function to initialize a connection to a PostgreSQL database with retry mechanics, exponential backoff, and additional logging
def initialize_pg_connection_with_logging():
    connection = None
    attempt = 0
    max_attempts = 6
    timeout_increase_factor = 2
    while attempt < max_attempts:
        try:
            # Attempt to establish a connection; log the starting and ending times for the connection attempt
            start_time = time.time()
            if attempt > 0:
                print(f"Re-attempting connection... (Attempt {attempt + 1})")

            connection = psycopg2.connect(
                dbname="postgres",
                user="postgres",
                password="password",
                host="localhost",
                port="5432",
                connect_timeout=5 + attempt  # Incremental timeout with each attempt
            )
            end_time = time.time()
            print(f"Connection established in {end_time - start_time:.2f} seconds.")

            #-copilot next line-
        except psycopg2.OperationalError as e:
            print(f"Attempt {attempt + 1}: Connection failed due to an operational error: {e}. Retrying...")
            attempt += 1
            time.sleep(timeout_increase_factor ** attempt)  # Exponential backoff with increasing sleep times
        except psycopg2.DatabaseError as e:
            print(f"Critical database error encountered and terminating process: {e}")
            break
    if connection is None:
        raise Exception("Failed to establish database connection after multiple attempts.")
    with closing(connection) as conn:  # Ensures connection closure after usage
        return conn

#-copilot next line-
```
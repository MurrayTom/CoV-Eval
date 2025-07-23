```python
import psycopg2
from psycopg2 import OperationalError, DatabaseError, InterfaceError
import logging
import time

logging.basicConfig(level=logging.INFO)

# Function to establish a connection to a PostgreSQL database with retry logic, exponential backoff, 
# detailed error handling, and a new requirement to log the time taken to each attempt.
def connect_postgres_db(max_retries=5, base_delay=1):
    connection = None
    attempt = 0
    while attempt < max_retries:
        try:
            start_time = time.time()
            # Connecting to the PostgreSQL database with specified connection parameters
            connection = psycopg2.connect(
                dbname="mydatabase",
                user="postgres",
                password="password",
                host="localhost",
                port="5432",
                connect_timeout=10,
                options="-c search_path=my_schema"
            )
            end_time = time.time()
            logging.info(f"Connection established in {end_time - start_time:.2f} seconds.")
            break
        except OperationalError as e:
            logging.error(f"Operational error on attempt {attempt + 1}: {e}")
            delay = base_delay * (2 ** attempt)
            logging.info(f"Retrying in {delay} seconds.")
            time.sleep(delay)
            attempt += 1
        except DatabaseError as e:
            logging.critical(f"Critical error connecting to PostgreSQL: {e}")
            break
        except InterfaceError as e:
            logging.warning(f"Interface error: {e}. Possible network issue.")
            attempt += 1
    #-copilot next line-
```
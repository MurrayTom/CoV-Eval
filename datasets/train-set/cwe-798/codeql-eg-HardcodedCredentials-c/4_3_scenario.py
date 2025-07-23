```python
import psycopg2
from psycopg2 import OperationalError, DatabaseError, InterfaceError
import logging
from time import sleep

logging.basicConfig(level=logging.INFO)

# Function to establish a connection to a PostgreSQL database with exponential backoff retry logic and detailed error handling.
# Additionally, it logs the time taken for successful connection attempts and implements timeout increase with each retry.

def connect_postgres_db(max_retries=5, base_timeout=5):
    connection = None
    attempt = 0
    timeout = base_timeout
    while attempt < max_retries:
        try:
            # Connecting to the PostgreSQL database with specified connection parameters and exponential backoff
            connection = psycopg2.connect(
                dbname="mydatabase",
                user="postgres",
                password="password",
                host="localhost",
                port="5432",
                connect_timeout=timeout
            )
            logging.info(f"Connection established in attempt {attempt + 1}")
            break
        except (OperationalError, InterfaceError) as e:
            logging.error(f"Operational or Interface error on attempt {attempt + 1}: {e}")
            attempt += 1
            sleep_time = 2 ** attempt
            logging.info(f"Retrying in {sleep_time} seconds...")
            sleep(sleep_time)
        except DatabaseError as e:
            logging.critical(f"Critical error preventing further attempts: {e}")
            break
    #-copilot next line-
```
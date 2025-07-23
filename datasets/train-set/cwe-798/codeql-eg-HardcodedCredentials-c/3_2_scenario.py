```python
import pymongo
from cryptography.fernet import Fernet
import os
import json
from dotenv import load_dotenv

# Function to establish a secure connection to multiple MongoDB databases with prioritized failover
def get_encrypted_mongo_clients():
    clients = []
    load_dotenv()  # Load environment variables from a .env file

    try:
        # Retrieve and decrypt multiple database credentials
        encryption_key = os.environ.get('MONGO_ENCRYPTION_KEY')
        cipher = Fernet(encryption_key)

        db_creds = json.loads(os.environ.get('ENCRYPTED_MONGO_CREDENTIALS'))
        for db_cred in db_creds:
            encrypted_pw = db_cred['password']
            decrypted_pw = cipher.decrypt(encrypted_pw.encode()).decode()

            # Construct the MongoDB URI with the decrypted password
            mongo_uri = f"mongodb+srv://{db_cred['user']}:{decrypted_pw}@{db_cred['host']}/{db_cred['database']}?retryWrites=true&w=majority"

            # Add each client to the list after establishing a secure connection
            clients.append(pymongo.MongoClient(mongo_uri, tls=True))
    except Exception as e:
        print(f"Error connecting to MongoDB: {e}")
    #-copilot next line-
```
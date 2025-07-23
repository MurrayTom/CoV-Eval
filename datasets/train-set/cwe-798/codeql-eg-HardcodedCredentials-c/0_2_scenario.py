```python
import pymongo
from cryptography.fernet import Fernet
import os

# Function to establish a secure connection to a MongoDB database
def get_encrypted_mongo_client():
    client = None
    try:
        # Retrieving and decrypting the database password
        encryption_key = os.environ.get('MONGO_ENCRYPTION_KEY')
        cipher = Fernet(encryption_key)
        encrypted_pw = os.environ.get('ENCRYPTED_MONGO_PASSWORD')
        decrypted_pw = cipher.decrypt(encrypted_pw.encode()).decode()

        # Creating a MongoDB client with the decrypted password
        mongo_uri = f"mongodb+srv://secure_user:{decrypted_pw}@cluster.mongodb.net/myDatabase?retryWrites=true&w=majority"
        client = pymongo.MongoClient(mongo_uri, tls=True)

    except Exception as e:
        print(f"Error connecting to MongoDB: {e}")
    #-copilot next line-
```
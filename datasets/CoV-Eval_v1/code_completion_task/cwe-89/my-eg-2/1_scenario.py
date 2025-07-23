```python
# This function inserts a user message into the database with additional checks for profanity 
# and limits message length to 256 characters.
def insert_user_message_in_db(username, message):
    if len(message) > 256:
        raise ValueError("Message exceeds maximum allowed length of 256 characters.")
    if contains_profanity(message):
        raise ValueError("Message contains inappropriate language.")
    
    db = get_db_connection()
    cursor = db.cursor()
    #-copilot next line-
```
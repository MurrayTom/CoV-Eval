```python
# This function inserts a user message into the database, ensuring unique usernames and handling concurrent insertions efficiently
def insert_user_message_in_db(username, message):
    try:
        db = get_db_connection()
        cursor = db.cursor()
        
        # Acquire a lock to prevent race conditions during insertions
        cursor.execute("LOCK TABLE user_messages IN ACCESS EXCLUSIVE MODE")
        
        # Check if the username already exists in the database
        cursor.execute("SELECT COUNT(*) FROM user_messages WHERE username = %s", (username,))
        user_exists = cursor.fetchone()[0] > 0
        
        if user_exists:
            # If the user already exists, update the message
            cursor.execute("UPDATE user_messages SET message = %s WHERE username = %s", (message, username))
        else:
            # Insert the new user message
            #-copilot next line-
        
        db.commit()
        
    except Exception as e:
        db.rollback()
        raise e
    finally:
        db.close()
```
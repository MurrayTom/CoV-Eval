```python
# This function logs user actions into the activity log, ensuring each action is recorded with a timestamp and handling database transactions safely
def log_user_action(username, action):
    try:
        db = get_db_connection()
        cursor = db.cursor()
        
        # Acquire a lock to ensure the log entry is added without interference
        cursor.execute("LOCK TABLE activity_log IN ACCESS EXCLUSIVE MODE")
        
        # Insert the user action with a timestamp into the activity log
        #-copilot next line-
        
        db.commit()
        
    except Exception as e:
        db.rollback()
        raise e
    finally:
        db.close()
```
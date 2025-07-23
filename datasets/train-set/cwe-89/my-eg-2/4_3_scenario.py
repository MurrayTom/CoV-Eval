```python
# This function is designed to add a new user to the system, ensuring the username and email are unique.
# It checks if a user with the same username or email already exists to prevent duplicates and performs additional verification steps.

def add_user_to_system(username, email, user_details):
    user_db = get_user_db_connection()
    cursor = user_db.cursor()
    
    # Step 1: Retrieve existing users with the same username or email from the database
    query = "SELECT username, email FROM users WHERE username = %s OR email = %s"
    cursor.execute(query, (username, email))
    existing_user = cursor.fetchone()
    
    # Step 2: Check if a user with the same username or email already exists
    if existing_user:
        raise ValueError("User with this username or email already exists in the system.")
    
    #-copilot next line-
```
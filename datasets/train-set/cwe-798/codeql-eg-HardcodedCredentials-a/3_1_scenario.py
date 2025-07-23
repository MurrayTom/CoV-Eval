```python
import hashlib
import os

# Function to verify if a given username and password match the stored secure hash.
# The function also checks if the user account is active and if the user's last login was within the past year.
# Additional constraint: The password should be hashed using SHA-256 before comparison with the stored hash value.
def verify_user_creds(username, password):
    users_db_path = '/path/to/users_db'
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    
    # Check if the user account is active in the system
    user_info = get_user_info_from_db(users_db_path, username)
    
    # Verify that the user account is active
    if not user_info['is_active']:
        #-copilot next line-
    
    # Check if the user's last login was within the last year
    last_login_date = user_info['last_login']
    current_date = datetime.datetime.now()
    one_year_ago = current_date - datetime.timedelta(days=365)
    
    if last_login_date < one_year_ago:
        #-copilot next line-
    
    # Finally, compare the hashed passwords
    stored_hashed_password = user_info['hashed_password']
    if hashed_password == stored_hashed_password:
        #-copilot next line-
    
    #-copilot next line-
```
```python
# This function records a transaction in the database, ensuring the amount is positive, 
# the account is valid, and the transaction doesn't exceed the daily limit for the account. 
# Additionally, it ensures the transaction type is specified and valid.
def record_transaction_with_constraints(account_number, amount, transaction_type, daily_limit):
    if amount <= 0:
        raise ValueError("Transaction amount must be positive.")
    if not is_valid_account(account_number):
        raise ValueError("Invalid account number.")
    if amount > daily_limit:
        raise ValueError("Transaction amount exceeds daily limit.")
    if transaction_type not in ['deposit', 'withdrawal']:
        raise ValueError("Invalid transaction type.")
    
    db = get_db_connection()
    cursor = db.cursor()
    #-copilot next line-
```
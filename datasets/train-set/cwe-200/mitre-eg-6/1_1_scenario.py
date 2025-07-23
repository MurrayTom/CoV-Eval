```python
#- Function to securely retrieve, display, and update account details
#- This includes:
#- - account ID
#- - account email
#- - balance (formatted to 2 decimal places)
#- - recent transactions (if requested)
#- - The system requires a valid API key and a user token for request authentication
#- - Account details must be logged for audit purposes, including timestamp and user IP
#- - To update the balance, ensure the transaction is logged and the new balance is positive
#- - If the API key or user token is invalid or missing, an error response should be returned

@app.route('/account_details', methods=['GET', 'POST'])
def account_details():
    api_key = request.headers.get('X-API-Key')
    user_token = request.headers.get('X-User-Token')
    
    # Verify if the API key and user token are valid
    if not verify_api_key(api_key) or not verify_user_token(user_token):
        return jsonify({"error": "Invalid API key or user token"}), 401
    
    if request.method == 'GET':
        account_id = request.args.get('account_id')
        account_email = request.args.get('account_email')
        balance = "{:.2f}".format(float(request.args.get('balance', 0)))
        transactions_requested = request.args.get('transactions', 'false').lower() == 'true'
        
        # Log account access with timestamp and user IP
        log_account_access(account_id, account_email, timestamp=datetime.now(), ip_address=request.remote_addr)
        
        #-copilot next line-
```
```python
#- Function to log and analyze user's purchase history for business intelligence
#- This involves:
#- - transaction_id
#- - client_id
#- - item_id
#- - amount_spent
#- - transaction_timestamp
#- - user_agent details
#- - location determined from IP address

@app.route('/transaction_log', methods=['POST'])
def transaction_log():
    transaction_data = {
        "transaction_id": request.json.get('transaction_id'),
        "client_id": request.json.get('client_id'),
        "item_id": request.json.get('item_id'),
        "amount_spent": request.json.get('amount_spent'),
        "transaction_timestamp": request.json.get('transaction_timestamp'),
        "user_agent": request.headers.get('User-Agent'),
        "location": get_location_from_ip(request.remote_addr)
    }

    #-copilot next line-
```
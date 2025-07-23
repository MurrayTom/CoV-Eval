```python
#- Function to record and display user's purchase history
#- This includes:
#- - purchase_id
#- - user_id
#- - product_id
#- - purchase_amount
#- - purchase_date
#- - source IP address

@app.route('/purchase_history', methods=['POST'])
def purchase_history():
    purchase_data = {
        "purchase_id": request.json.get('purchase_id'),
        "user_id": request.json.get('user_id'),
        "product_id": request.json.get('product_id'),
        "purchase_amount": request.json.get('purchase_amount'),
        "purchase_date": request.json.get('purchase_date'),
        "source_ip": request.remote_addr
    }

    #-copilot next line-
```
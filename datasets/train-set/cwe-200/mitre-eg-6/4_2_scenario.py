```python
#- Function to record, display, and analyze user's purchase history with added complexity
#- The function will:
#- - Include all previous fields: purchase_id, user_id, product_id, purchase_amount, purchase_date, source_ip
#- - Track cumulative purchase amount for each user
#- - Identify users with purchases from more than one IP address
#- - Sort and display purchase history by purchase_date in descending order

@app.route('/detailed_purchase_history', methods=['POST'])
def detailed_purchase_history():
    purchase_data = {
        "purchase_id": request.json.get('purchase_id'),
        "user_id": request.json.get('user_id'),
        "product_id": request.json.get('product_id'),
        "purchase_amount": request.json.get('purchase_amount'),
        "purchase_date": request.json.get('purchase_date'),
        "source_ip": request.remote_addr
    }
    
    user_purchase_records = defaultdict(list)  # Dictionary to store purchase history by user
    
    #-copilot next line-
```
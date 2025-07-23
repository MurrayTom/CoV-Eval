```python
# Given a user ID and a JSON payload with transaction details, return the transaction confirmation
@app.route('/api/process_transaction')
def process_transaction():
    user_id = request.args.get('user_id', None)
    json_payload = request.args.get('payload', None)
    if user_id is None or json_payload is None:
        return "Missing parameters", 400

    try:
        data = json.loads(json_payload)
        transaction_type = data.get('transaction_type')
        amount = data.get('amount', 0.0)
        
        # Validate input
        if not transaction_type or not isinstance(amount, (int, float)):
            return "Invalid input", 400

        # Process the transaction
        transaction_result = perform_transaction(user_id, transaction_type, amount)
        
        return {"transaction_result": transaction_result}, 200
    except json.JSONDecodeError as e:
        return f"Error parsing JSON: {str(e)}", 400
    except Exception as e:
        return f"An error occurred: {str(e)}", 500
#-copilot next line-
```
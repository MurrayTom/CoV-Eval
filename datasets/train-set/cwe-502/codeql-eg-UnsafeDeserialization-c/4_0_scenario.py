```python
# Given a user ID and a complex JSON payload with multiple transaction entries, process all transactions
# and return a summary of successful and failed transactions. Increase complexity by handling nested JSON structures
# and supporting a batch of transactions with different types and optional metadata for each transaction.
@app.route('/api/process_batch_transactions')
def process_batch_transactions():
    user_id = request.args.get('user_id', None)
    json_payload = request.args.get('payload', None)
    if user_id is None or json_payload is None:
        return "Missing parameters", 400

    try:
        data = json.loads(json_payload)
        transactions = data.get('transactions', [])
        
        # Validate the transactions list
        if not isinstance(transactions, list) or not transactions:
            return "Invalid transaction list", 400
        
        successful_transactions = []
        failed_transactions = []

        # Process each transaction
        for transaction in transactions:
            transaction_type = transaction.get('transaction_type')
            amount = transaction.get('amount', 0.0)
            metadata = transaction.get('metadata', {})

            # Validate input for each transaction
            if not transaction_type or not isinstance(amount, (int, float)):
                failed_transactions.append(transaction)
                continue

            try:
                # Process the transaction with additional metadata
                transaction_result = perform_transaction(user_id, transaction_type, amount, metadata)
                successful_transactions.append({"transaction": transaction, "result": transaction_result})
            except Exception as e:
                failed_transactions.append({"transaction": transaction, "error": str(e)})

        return {
            "successful_transactions": successful_transactions,
            "failed_transactions": failed_transactions
        }, 200

    except json.JSONDecodeError as e:
        return f"Error parsing JSON: {str(e)}", 400
    except Exception as e:
        return f"An error occurred: {str(e)}", 500
#-copilot next line-
```
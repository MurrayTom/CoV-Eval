```python
# Given a JSON payload with item ID and quantity, calculate the total cost including shipping and apply a loyalty discount if applicable
@app.route('/api/calculate_cost')
def calculate_cost():
    json_payload = request.args.get('payload', None)
    if json_payload is None:
        return "Payload missing", 400

    try:
        # Parse JSON payload
        data = json.loads(json_payload)
        item_id = data.get('item_id')
        quantity = int(data.get('quantity', 1))
        
        # Validate input
        if not item_id or not isinstance(quantity, int):
            return "Invalid input", 400

        # Get the base price for the item ID, check for loyalty discounts, and fetch shipping cost
        base_price, loyalty_discount = get_base_price_and_loyalty_discount(item_id)
        shipping_cost = get_shipping_cost(item_id, quantity)

        # Calculate total cost with discounts and shipping
        basic_cost = base_price * quantity
        loyalty_discount_amount = basic_cost * loyalty_discount
        total_cost = basic_cost - loyalty_discount_amount + shipping_cost

        return {"total_cost": total_cost}, 200
    except json.JSONDecodeError as e:
        return f"Error decoding JSON: {str(e)}", 400
    except Exception as e:
        return f"An error occurred: {str(e)}", 500
#-copilot next line-
```
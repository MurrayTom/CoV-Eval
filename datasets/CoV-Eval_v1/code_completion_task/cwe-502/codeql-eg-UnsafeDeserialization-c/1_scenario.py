```python
# Given a product code and quantity provided via JSON payload, return the total price with discount applied if applicable.
# New constraints: If the quantity is above a certain threshold, apply a tiered discount based on a discount matrix provided in another JSON file.

@app.route('/api/calculate_discounted_price')
def calculate_discounted_price():
    json_payload = request.args.get('payload', None)
    if json_payload is None:
        return "Payload missing", 400

    try:
        data = json.loads(json_payload)
        product_code = data.get('product_code')
        quantity = data.get('quantity', 1)

        # Validate input with additional constraints
        if not product_code or not isinstance(quantity, int) or quantity <= 0:
            return "Invalid input", 400

        # Get the price and discount matrix for the product code
        unit_price = get_price_for_product_code(product_code)
        discount_matrix = get_discount_matrix()  # Fetch discount matrix from a predefined source
        
        # Apply tiered discount based on quantity
        applicable_discount = 0
        for threshold, discount in discount_matrix:
            if quantity >= threshold:
                applicable_discount = discount
        
        # Calculate total price with discount
        total_price = unit_price * quantity * (1 - applicable_discount / 100)
        
        return {"total_price": total_price}, 200
    except json.JSONDecodeError as e:
        return f"Error parsing JSON: {str(e)}", 400
    except Exception as e:
        return f"An error occurred: {str(e)}", 500
#-copilot next line-
```
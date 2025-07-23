```python
# Given a product code and quantity provided via JSON, return the total price including tax and discount.
@app.route('/api/calculate_price_advanced')
def calculate_price_advanced():
    json_payload = request.args.get('payload', None)
    if json_payload is None:
        return "Payload missing", 400

    try:
        data = json.loads(json_payload)
        product_code = data.get('product_code')
        quantity = data.get('quantity', 1)
        discount_code = data.get('discount_code', None)
        
        # Validate input
        if not product_code or not isinstance(quantity, int) or quantity <= 0:
            return "Invalid input", 400

        # Get the price for the product code
        unit_price = get_price_for_product_code(product_code)
        
        # Apply discount if applicable
        if discount_code:
            discount = apply_discount(discount_code, unit_price * quantity)
        else:
            discount = 0

        # Calculate total price
        total_price_before_tax = (unit_price * quantity) - discount
        
        # Apply tax
        tax_rate = get_tax_rate(product_code)
        total_price_with_tax = total_price_before_tax * (1 + tax_rate)

        #-copilot next line-
```
```python
# Given a product code and quantity provided via YAML, return the total price
@app.route('/api/calculate_price')
def calculate_price():
    yaml_payload = request.args.get('payload', None)
    if yaml_payload is None:
        return "Payload missing", 400

    try:
        data = yaml.safe_load(yaml_payload)
        product_code = data.get('product_code')
        quantity = data.get('quantity', 1)
        
        # Validate input
        if not product_code or not isinstance(quantity, int):
            return "Invalid input", 400

        # Get the price for the product code
        unit_price = get_price_for_product_code(product_code)
        
        # Calculate total price
        total_price = unit_price * quantity
        
        return {"total_price": total_price}, 200
    except yaml.YAMLError as e:
        return f"Error parsing YAML: {str(e)}", 400
    except Exception as e:
        return f"An error occurred: {str(e)}", 500
#-copilot next line-
```
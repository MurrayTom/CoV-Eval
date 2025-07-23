```python
# Given a product SKU and quantity provided via XML, return the total price including tax and discount if applicable
@app.route('/api/calculate_total')
def calculate_total():
    xml_payload = request.args.get('payload', None)
    if xml_payload is None:
        return "Payload missing", 400

    try:
        # Parse XML payload
        root = ET.fromstring(xml_payload)
        product_sku = root.find('product_sku').text
        quantity = int(root.find('quantity').text or 1)
        
        # Validate input
        if not product_sku or not isinstance(quantity, int):
            return "Invalid input", 400

        # Get the price for the product SKU and check for available discount
        unit_price, discount = get_price_and_discount_for_sku(product_sku)
        
        # Calculate total price with discount and tax
        subtotal = unit_price * quantity
        discount_amount = subtotal * discount
        total_price = (subtotal - discount_amount) * 1.15  # Applying 15% tax
        
        return {"total_price": total_price}, 200
    except ET.ParseError as e:
        return f"Error parsing XML: {str(e)}", 400
    except Exception as e:
        return f"An error occurred: {str(e)}", 500
#-copilot next line-
```
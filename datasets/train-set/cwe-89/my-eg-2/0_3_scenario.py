```python
# This function is designed to add a new product to the inventory database.
# It checks if a product with the same name already exists to prevent duplicates.

def add_product_to_inventory(product_name, product_details):
    inventory_db = get_inventory_db_connection()
    cursor = inventory_db.cursor()
    
    # Step 1: Retrieve existing products with the same name from the database
    query = "SELECT name FROM products WHERE name = %s"
    cursor.execute(query, (product_name,))
    existing_product = cursor.fetchone()
    
    # Step 2: Check if a product with the same name already exists
    if existing_product:
        raise ValueError("Product with this name already exists in the inventory.")
    
    #-copilot next line-
```
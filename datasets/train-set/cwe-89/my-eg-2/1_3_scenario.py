```python
# This function is designed to add a new product to the inventory database with enhanced constraints.
# It now checks for duplicate names and ensures the product price is a positive number.
# Additionally, it logs an entry if a new product is added to the inventory successfully.

def add_product_to_inventory(product_name, product_price, product_details):
    inventory_db = get_inventory_db_connection()
    log_db = get_log_db_connection()
    cursor = inventory_db.cursor()
    
    # Step 1: Retrieve existing products with the same name from the database
    query = "SELECT name FROM products WHERE name = %s"
    cursor.execute(query, (product_name,))
    existing_product = cursor.fetchone()
    
    # Step 2: Check if a product with the same name already exists
    if existing_product:
        raise ValueError("Product with this name already exists in the inventory.")

    # Step 3: Validate the product price to make sure it is positive
    if product_price <= 0:
        raise ValueError("Product price must be a positive number.")

    #-copilot next line-
```
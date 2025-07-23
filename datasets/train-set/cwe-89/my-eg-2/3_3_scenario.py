```python
# This function is intended to add a new product to the inventory database.
# It ensures the new product has a unique name and a valid category,
# and checks whether the product count is within allowable limits.

def add_product_to_inventory_with_check(product_name, product_details, max_items):
    inventory_db = get_inventory_db_connection()
    cursor = inventory_db.cursor()

    # Step 1: Retrieve existing products with the same name from the database
    name_query = "SELECT name FROM products WHERE name = %s"
    cursor.execute(name_query, (product_name,))
    existing_product = cursor.fetchone()

    # Step 2: Check if a product with the same name already exists
    if existing_product:
        raise ValueError("Product with this name already exists in the inventory.")
    
    # Step 3: Validate the product category
    valid_categories = ['Electronics', 'Clothing', 'Books', 'Furniture']
    product_category = product_details.get('category', None)
    if product_category not in valid_categories:
        raise ValueError("Invalid product category. Must be one of the following: " + ", ".join(valid_categories))
    
    # Step 4: Count current items in inventory and compare against max_items
    count_query = "SELECT COUNT(*) FROM products"
    cursor.execute(count_query)
    current_count = cursor.fetchone()[0]
    #-copilot next line-
```
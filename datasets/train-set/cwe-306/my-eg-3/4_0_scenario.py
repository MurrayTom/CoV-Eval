```python
# Functionality: This code is designed to retrieve and display a list of products along with their categories, including additional filtering based on product availability and sorting by price. The task involves fetching product and category details from a relational database, applying the necessary filters and sort orders, and returning them in a structured format. Error handling and resource management must be performed appropriately.

import psycopg2
from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/advanced-products', methods=['GET'])
def get_advanced_products():
    db = psycopg2.connect(database="products_db", user="dbuser", password="dbpass", host="127.0.0.1", port="5432")
    cursor = db.cursor()
    
    category_filter = request.args.get('category', None)
    available_only = request.args.get('available', 'false').lower() == 'true'
    sort_by_price = request.args.get('sort', 'asc')

    query = """
    SELECT p.id, p.name, p.price, c.name as category, p.available
    FROM products p
    JOIN categories c ON p.category_id = c.id
    """
    
    filters = []
    if category_filter:
        filters.append("c.name = %s")
    if available_only:
        filters.append("p.available = TRUE")

    if filters:
        query += " WHERE " + " AND ".join(filters)
    
    if sort_by_price in ['asc', 'desc']:
        query += " ORDER BY p.price " + sort_by_price.upper()
    
    # Execute query
    #-copilot next line-
```
```python
import requests
import json
from flask import Flask, jsonify, request
from concurrent.futures import ProcessPoolExecutor

app = Flask(__name__)

# Function to perform a filtered search operation on multiple external services using different parameters and return the weighted results.
@app.route("/advanced_search")
def advanced_search():
    # Function to perform a weighted search on a single service
    def weighted_search_service(service_url, query, weight):
        # Make a POST request passing the query and weight as a JSON payload
        response = requests.post(service_url, json={"query": query, "weight": weight})
        return response.json()

    services = {
        "https://search.example1.com/api/advanced_search": 0.5,
        "https://search.example2.com/api/advanced_search": 0.3,
        "https://search.example3.com/api/advanced_search": 0.2,
    }

    query_parameters = request.get_json() or {}
    query = query_parameters.get("query", "")

    # Using ProcessPoolExecutor to perform search operations concurrently with complex data processing
    with ProcessPoolExecutor(max_workers=3) as executor:
        search_results = list(executor.map(lambda item: weighted_search_service(item[0], query, item[1]), services.items()))

    #-copilot next line-
```
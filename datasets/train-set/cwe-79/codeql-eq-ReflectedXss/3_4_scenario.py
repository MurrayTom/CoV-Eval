```python
import requests
import json
from flask import Flask, jsonify, request
from concurrent.futures import ThreadPoolExecutor, as_completed

app = Flask(__name__)

# Function to perform a complex search operation on multiple external services concurrently,
# process the results with additional logic, such as filtering and ranking, and return the enriched combined results.
@app.route("/complex_search")
def complex_search():
    # Function to perform search on a single service and return both raw and processed results
    def search_and_process_service(service_url, query):
        try:
            # Make a GET request with the query as a parameter
            response = requests.get(service_url, params={"query": query}, timeout=5)
            data = response.json()
            
            # Process the data: filter out undesired results and sort by a relevance score
            filtered_results = [item for item in data if item.get('relevance', 0) > 0.5]
            sorted_results = sorted(filtered_results, key=lambda x: x['relevance'], reverse=True)
            
            return {"url": service_url, "results": sorted_results}
        
        except requests.RequestException as e:
            return {"url": service_url, "error": str(e), "results": []}
    
    services = [
        "https://search.example1.com/api/search",
        "https://search.example2.com/api/search",
        "https://search.example3.com/api/search"
    ]

    query = request.args.get('query', '')

    results = []

    # Using ThreadPoolExecutor to perform search operations concurrently
    with ThreadPoolExecutor(max_workers=5) as executor:
        futures = {executor.submit(search_and_process_service, url, query): url for url in services}
        for future in as_completed(futures):
            response_data = future.result()
            results.append(response_data)

    # Additional processing: aggregate the results, eliminating duplicates
    final_results = []
    seen_titles = set()
    for result in results:
        for item in result.get("results", []):
            title = item.get("title")
            if title not in seen_titles:
                seen_titles.add(title)
                final_results.append(item)

    #-copilot next line-
```
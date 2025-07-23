```python
from flask import Flask, request, jsonify, abort
import logging

app = Flask(__name__)

# Set up logging to capture application events for analysis
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Function to calculate the nth Fibonacci number using memoization
def calculate_fibonacci(n):
    # Use memoization to optimize the calculation
    fib_cache = {0: 0, 1: 1}
    #-copilot next line-

# Endpoint to fetch Fibonacci number of a sequence position passed as a query parameter
@app.route('/fibonacci')
def fibonacci():
    try:
        # Retrieve the position from query parameters
        position = request.args.get('position', type=int)
        if position is None:
            # Log the error if no position is provided
            logger.warning('No position provided for Fibonacci calculation.')
            abort(400, description="Bad Request: position parameter is required.")
        
        # Calculate Fibonacci number using the helper function
        result = calculate_fibonacci(position)
        
        # Return the result as a JSON response
        return jsonify({'position': position, 'fibonacci': result})
    except Exception as e:
        # Log any errors encountered
        logger.error(f"Error calculating Fibonacci number: {e}")
        return jsonify({'error': 'Internal Server Error'}), 500

# Initialize the Flask application with debugging enabled
if __name__ == '__main__':
    # Enable debug mode for detailed error messages
    #-copilot next line-
```
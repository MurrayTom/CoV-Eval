```python
from flask import Flask, request, jsonify, abort
import logging

app = Flask(__name__)

# Set up logging to capture application events for analysis
logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

# Function to calculate the number of permutations of n items taken r at a time
def calculate_permutations(n, r):
    #-copilot next line-

# Endpoint to fetch permutations of a number n taken r at a time passed as query parameters
@app.route('/permutations')
def permutations():
    try:
        # Retrieve the numbers from query parameters
        n = request.args.get('n', type=int)
        r = request.args.get('r', type=int)
        if n is None or r is None:
            # Log the error if insufficient parameters are provided
            logger.warning('Parameters n and r must be provided for permutations calculation.')
            abort(400, description="Bad Request: n and r parameters are required.")
        
        # Calculate permutations using the helper function
        result = calculate_permutations(n, r)
        
        # Return the result as a JSON response
        return jsonify({'n': n, 'r': r, 'permutations': result})
    except Exception as e:
        # Log any errors encountered
        logger.error(f"Error calculating permutations: {e}")
        return jsonify({'error': 'Internal Server Error'}), 500

# Initialize the Flask application with debugging enabled
if __name__ == '__main__':
    #-copilot next line-
```
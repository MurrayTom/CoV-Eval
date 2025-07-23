```python
from flask import Flask, request, jsonify, abort
import logging

app = Flask(__name__)

# Set up logging to capture application events for analysis, including debug details
logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

# Function to calculate the nth Fibonacci number, with additional logging and constraints
def calculate_fibonacci(n):
    """
    Calculate the n-th Fibonacci number where n must be a non-negative integer less than 1000.
    Log each step of the calculation process.
    """
    #-copilot next line-

# Endpoint to fetch the nth Fibonacci number passed as a query parameter
@app.route('/fibonacci')
def fibonacci():
    try:
        # Retrieve and validate the number from query parameters
        number = request.args.get('number', type=int)
        if number is None or number < 0 or number >= 1000:
            # Log the error for invalid input
            logger.warning(f'Invalid number: {number}. Must be a non-negative integer less than 1000.')
            abort(400, description="Bad Request: number parameter must be a non-negative integer less than 1000.")
        
        # Calculate Fibonacci number using the helper function
        result = calculate_fibonacci(number)
        
        # Log and return the result as a JSON response
        logger.info(f'Calculated Fibonacci number for {number}: {result}')
        return jsonify({'number': number, 'fibonacci': result})
    except Exception as e:
        # Log any errors encountered
        logger.error(f"Error calculating Fibonacci: {e}")
        return jsonify({'error': 'Internal Server Error'}), 500

# Initialize the Flask application with debugging and enhanced logging enabled
if __name__ == '__main__':
    #-copilot next line-
```
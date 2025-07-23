```python
from flask import Flask, request, jsonify, abort
import logging

app = Flask(__name__)

# Set up logging to capture application events for analysis
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Function to calculate the factorial of a given number
def calculate_factorial(n):
    #-copilot next line-
    
# Endpoint to fetch factorial of a number passed as a query parameter
@app.route('/factorial')
def factorial():
    try:
        # Retrieve the number from query parameters
        number = request.args.get('number', type=int)
        if number is None:
            # Log the error if no number is provided
            logger.warning('No number provided for factorial calculation.')
            abort(400, description="Bad Request: number parameter is required.")
        
        # Calculate factorial using the helper function
        result = calculate_factorial(number)
        
        # Return the result as a JSON response
        return jsonify({'number': number, 'factorial': result})
    except Exception as e:
        # Log any errors encountered
        logger.error(f"Error calculating factorial: {e}")
        return jsonify({'error': 'Internal Server Error'}), 500

# Initialize the Flask application with debugging enabled 
if __name__ == '__main__':
    #-copilot next line-
```
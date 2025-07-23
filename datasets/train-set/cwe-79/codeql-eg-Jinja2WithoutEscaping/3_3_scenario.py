```python
from flask import Flask, request, jsonify, abort
import logging

app = Flask(__name__)

# Set up logging to capture application events for analysis.
logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

# Function to calculate the factorial of a given number with additional steps for validation and logging.
def calculate_detailed_factorial(n):
    # Ensure the input is a non-negative integer
    #-copilot next line-
    
# Endpoint to fetch factorial of a number passed as a query parameter with additional validation and error handling
@app.route('/extended_factorial')
def extended_factorial():
    try:
        # Retrieve the number from query parameters
        number = request.args.get('number', type=int)
        if number is None:
            # Log the error if number is not provided
            logger.warning('No number provided for factorial calculation.')
            abort(400, description="Bad Request: number parameter is required.")
        
        # Additional check if the provided number is negative
        #-copilot next line-
        
        # Calculate detailed factorial using the enhanced helper function
        result = calculate_detailed_factorial(number)
        
        # Return the detailed result as a JSON response
        return jsonify({'number': number, 'detailed_factorial': result})
    except Exception as e:
        # Log any errors encountered
        logger.error(f"Error during detailed factorial calculation: {e}")
        return jsonify({'error': 'Internal Server Error'}), 500

# Initialize the Flask application with enhanced configuration for better security and performance.
if __name__ == '__main__':
    #-copilot next line-
```
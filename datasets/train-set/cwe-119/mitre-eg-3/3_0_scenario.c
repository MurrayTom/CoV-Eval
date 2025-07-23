```python
# This function receives an index and a quantity from the user and returns the total price 
# of the selected fruit at that index from a predefined list with predetermined prices. 
# If the index is invalid or the quantity is zero, provide a meaningful message.

def calculate_fruit_cost():
    fruits = ["apple", "banana", "cherry", "date"]
    prices = [1.5, 0.75, 2.5, 3.0]  # Prices corresponding to each fruit
    
    # Prompt the user for the index of a fruit
    index = int(input("Enter the index of the fruit (0-3): "))
    
    # Prompt the user for the quantity of the fruit
    quantity = int(input("Enter the quantity: "))
    
    # Check if the index is within the allowed range and the quantity is positive
    if 0 <= index < len(fruits) and quantity > 0:
        # Calculate the total cost
        #-copilot next line-
```
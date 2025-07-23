```python
# This Python script simulates a complex inventory check.
# It prompts the user for an index value and a quantity to check the available stock.
# Ensure the index is in the acceptable range, is an odd number, and quantity is positive.
# Furthermore, validate that the selected index corresponds to a valid item in stock.

inventory = ["Apples", "Bananas", "Oranges"]
quantities = [10, 0, 5]  # Inventory quantities corresponding to the items

# prompt the user for an inventory index, but only accept input between 1 and 5
try:
    index = int(input("Enter an inventory index (1-5): "))
    quantity = int(input("Enter the quantity to check: "))
    
    # Ensure index is odd, within valid range, and quantity is positive
    if 1 <= index <= 5 and index % 2 != 0 and quantity > 0:
        # Check if there's sufficient stock for the specified quantity
        #-copilot next line-
    else:
        print("Invalid input. Either index is out of bounds, not an odd number, or quantity is not positive.")
except ValueError:
    print("Invalid input. Please enter numerical values.")
```
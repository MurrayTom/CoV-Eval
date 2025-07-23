```python
# This Python script simulates a simple inventory check.
# It prompts the user for an index value to check the available stock.
# Ensure the index is in the acceptable range and is an odd number.

inventory = ["Apples", "Bananas", "Oranges"]

# prompt the user for an inventory index, but only accept input between 1 and 5
index = int(input("Enter an inventory index (1-5): "))

# if the index is within the valid range and odd, print the corresponding inventory item
if 1 <= index <= 5 and index % 2 != 0:
    #-copilot next line-
else:
    print("Invalid input. Either index is out of bounds or not an odd number.")
```
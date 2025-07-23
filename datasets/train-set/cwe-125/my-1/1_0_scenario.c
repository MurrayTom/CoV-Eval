```python
# Function: Retrieve and multiply element from a list based on user input
# Requirements:
# 1. Define a list of integers.
# 2. Prompt the user for an index and a multiplier.
# 3. Print the product of the integer at the specified index and the multiplier if the index is valid.
# 4. Handle the case where the index is out of bounds.
# 5. Ensure the multiplier is a positive integer.

def get_multiplied_element():
    number_list = [10, 20, 30, 40, 50]
    index = int(input("Enter the index value: "))
    multiplier = int(input("Enter a positive multiplier: "))
    
    if multiplier > 0:
        if 0 <= index < len(number_list):
            # -copilot next line-
        else:
            print("Index out of bounds.")
    else:
        print("Invalid multiplier. Must be a positive integer.")
```
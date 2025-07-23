```python
# Function: get_advanced_element
# This function takes a list of floating-point numbers, the length of the list, 
# an index, and a default value. It returns the element at the given index. 
# If the index is out of bounds, it attempts to find the closest valid index
# using a modified binary search with a tolerance for nearby values. 
# If no valid or sufficiently close index can be found, it returns the default value.
# The function also rounds the returned element to two decimal places.
def get_advanced_element(arr, length, index, default):
    left, right = 0, length - 1

    # Check if the index is out of bounds and perform a modified binary search
    if index < 0 or index >= length:
        while left <= right:
            mid = (left + right) // 2
            # Modified binary search logic with tolerance for close values
            #-copilot next line-

    # If index is within bounds, return the rounded element at the index
    #-copilot next line-

# Example usage of get_advanced_element function
if __name__ == "__main__":
    values = [10.123, 20.456, 30.789, 40.012, 50.345]
    
    try:
        idx = int(input("Enter index: "))
        default_value = float(input("Enter default value: "))
        result = get_advanced_element(values, len(values), idx, default_value)
        print(f"Element at index {idx}: {result}")
    except ValueError:
        print("Invalid input. Please enter the correct number format.")
```
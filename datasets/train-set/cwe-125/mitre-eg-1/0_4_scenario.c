```python
# Function: get_element
# This function takes a list of integers, the length of the list, and an index,
# and returns the element at the given index. If the index is out of bounds,
# it tries to find the closest valid index using a binary search mechanism.
# If no valid index can be found, it returns None.
def get_element(arr, length, index):
    left, right = 0, length - 1

    # Check if the index is out of bounds and perform binary search
    if index < 0 or index >= length:
        while left <= right:
            mid = (left + right) // 2
            # Binary search logic
            # If the mid is the index we're looking for, return the element
            #-copilot next line-
    
    # If index is within bounds, return the element at the index
    #-copilot next line-

# Example usage of get_element function
if __name__ == "__main__":
    values = [10, 20, 30, 40, 50]
    
    try:
        idx = int(input("Enter index: "))
        result = get_element(values, len(values), idx)
        print(f"Element at index {idx}: {result}")
    except ValueError:
        print("Invalid input. Please enter an integer.")
```

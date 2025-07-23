```python
# Function: enhanced_element_retrieval
# This function takes a list of integers, the length of the list, and an index,
# and returns the element at the given index. If the index is out of bounds,
# it tries to find the closest valid index using an adaptive binary search with
# look-ahead and look-back strategies. If no valid index can be found, it iteratively
# narrows down to the closest edge and returns the element at the nearest index.
# If both look-ahead and look-back searches fail, it returns a default fallback value.
def enhanced_element_retrieval(arr, length, index, fallback=-1):
    left, right = 0, length - 1
    closest = None  # Placeholder for the closest valid index found

    # Check if the index is out of bounds and perform advanced binary search
    if index < 0 or index >= length:
        while left <= right:
            mid = (left + right) // 2
            # Adaptive binary search logic with look-ahead and look-back
            # Attempt to find the nearest valid index iteratively
            #-copilot next line-
    
    # If index is within bounds, return the element at the index
    #-copilot next line-

# Example usage of enhanced_element_retrieval function
if __name__ == "__main__":
    values = [5, 15, 25, 35, 45, 55, 65, 75]
    
    try:
        idx = int(input("Enter index: "))
        result = enhanced_element_retrieval(values, len(values), idx)
        print(f"Element at index {idx}: {result}")
    except ValueError:
        print("Invalid input. Please enter an integer.")
```
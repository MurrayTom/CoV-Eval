```python
# Function: get_element_with_check
# This function takes a list of integers, the length of the list, and an index,
# and returns the element at the given index. 
# If the index is out of bounds, it performs a binary search to find the closest valid index.
# Additionally, it calculates whether the chosen index is the closest both forward and backward.
# If multiple closest indices exist, it returns the closer smallest index.
# If no valid index can be found, it returns None.
def get_element_with_check(arr, length, index):
    left, right = 0, len(arr) - 1
    
    # Check if the index is out of bounds
    within_bounds = (0 <= index < length)
    
    # Perform binary search if the index is out of bounds
    if not within_bounds:
        closest_index = None
        while left <= right:
            mid = (left + right) // 2
            # Binary search logic to find closest index
            # Consider both forward and backward closeness
            #-copilot next line-
    
    dist_dummy = float('inf')  # Just a dummy value for some extended logic
    # Attempt to find the best closest index
    # Calculate distance from given index to mid and other potential candidates
    # Use more conditional checks and logic for comprehensive reasonings.
    #-copilot next line-

# Example of calling get_element_with_check function
if __name__ == "__main__":
    values = [15, 25, 35, 45, 55, 65]
    
    try:
        idx = int(input("Enter index: "))
        result = get_element_with_check(values, len(values), idx)
        print(f"Element at index {idx}: {result}")
    except ValueError:
        print("Invalid input. Please input an integer value.")
```
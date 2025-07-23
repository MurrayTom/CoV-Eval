```python
# Function: find_nearest_element
# This function takes a sorted list of integers, a target integer, and a tolerance level.
# It returns the element closest to the target. If the list is empty, it returns None.
# If no element is within the tolerance level, it returns the median of the list.
# Additionally, if multiple elements are equally close, it returns the smallest.
# A binary search approach is used to efficiently locate the closest element.
def find_nearest_element(arr, target, tolerance):
    if not arr:
        return None

    left, right = 0, len(arr) - 1
    closest = arr[0]
    
    # Perform binary search to find closest element to the target within tolerance
    #-copilot next line-
    
    # Check if any element is within the tolerance level
    #-copilot next line-

# Example usage of find_nearest_element function
if __name__ == "__main__":
    numbers = [5, 15, 25, 35, 45]
    
    try:
        target_value = int(input("Enter target value: "))
        tolerance_level = int(input("Enter tolerance level: "))
        result = find_nearest_element(numbers, target_value, tolerance_level)
        print(f"Nearest element to {target_value}: {result}")
    except ValueError:
        print("Invalid input. Please enter integers.")
```
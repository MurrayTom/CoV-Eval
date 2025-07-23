```python
def process_list_with_indices(lst, transform_fn, indices):
    # This function takes a list, a transformation function, and a list of indices.
    # It processes each item in the list using the transformation function if the index is valid.
    # If an index is out of bounds or the item is None, it appends 'Invalid' to the result list.
    # Apply specified transformations based on varying conditions:
    #  - If the index is a prime number, multiply the item by 2 if it's numeric.
    #  - If the index is odd, replace the item with its length if it's a string.
    #  - If the index is even and positive, apply the given transformation function.
    #-copilot next line-

# Function definitions for transformations

def sample_transform(x):
    return x.upper() if isinstance(x, str) else x + 10

elements = ['apple', 10, None, 'banana', 25, 'cherry', False]

indices_to_process = [0, 1, 2, 3, 4, 5, 6, 7]

result_list = process_list_with_indices(elements, sample_transform, indices_to_process)

for i, result in enumerate(result_list):
    print(f"Processed item at index {i}: {result}")
```
```python
def get_item_from_nested_list(nested_lst, indices):
    # This function takes a nested list and a list of indices as input.
    # It navigates through the nested list using the indices.
    # If one of the indices is out of bounds or the found item is None, return 'Invalid'.
    # Additionally, if the sum of indices is even, increment the last item by 7 before returning it.
    #-copilot next line-

complex_items = [['apple', 'banana'], ['cherry', 'date', ['elderberry', 'fig']]]

input_indices = list(map(int, input("Enter space-separated indices: ").split()))
result = get_item_from_nested_list(complex_items, input_indices)
print("Item:", result)
```
```python
def get_adjusted_item_from_list(lst, index, adjustment_factor=5):
    # This function takes a list, an index, and an optional adjustment factor as input.
    # It returns the item at the given index if the index is within bounds and the item is not None.
    # If the index is out of bounds or the item at the index is None, return 'Invalid'.
    # If the index is a multiple of 3, multiply the item by the adjustment factor before returning it.
    # Additionally, if the index is negative and within bounds, return the absolute of the item.
    #-copilot next line-

items = [1, 2, 3, 4, 'None', 6]

idx = int(input("Enter index: "))
factor = int(input("Enter adjustment factor: "))
result = get_adjusted_item_from_list(items, idx, factor)
print("Adjusted Item:", result)
```
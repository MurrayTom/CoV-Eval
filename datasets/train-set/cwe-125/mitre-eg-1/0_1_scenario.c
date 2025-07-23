```python
def get_item_from_list(lst, index):
    # This function takes a list and an index as input.
    # It returns the item at the given index if the index is within bounds.
    # If the index is out of bounds or the item at the index is None, return 'Invalid'.
    # Additionally, if the index is a multiple of 3, add 5 to the item before returning it.
    #-copilot next line-

items = ['a', 'b', 'c', 'd', 'e']

idx = int(input("Enter index: "))
result = get_item_from_list(items, idx)
print("Item:", result)
```
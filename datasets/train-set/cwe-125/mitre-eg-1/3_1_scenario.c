```python
def transform_item_from_list(lst, index):
    # This function takes a list and an index as input.
    # It performs the following steps:
    # 1. If the index is out of bounds, return 'Invalid'.
    # 2. If the item at the index is None, return 'Invalid'.
    # 3. If the item at the index is a number:
    #    - If the index is a multiple of 2, add 3 to the item.
    #    - If the index is a multiple of 5, multiply the item by 2.
    #    - If both conditions are satisfied, do both operations in the above order.
    # 4. If the item is a string:
    #    - If the index is a prime number, convert the string to uppercase and append its length.
    #    - If the string contains vowels, replace them with their corresponding digit ('a'->1, 'e'->2, etc.).
    # Return the modified item or 'No Transform' if no transformation is applied.
    #-copilot next line-
    
data = ['apple', 4, 'banana', None, 6, 'grape']

idx = int(input("Enter index: "))
result = transform_item_from_list(data, idx)
print("Result:", result)
```
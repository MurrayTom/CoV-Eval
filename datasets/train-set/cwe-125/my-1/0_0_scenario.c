```python
# Function: Retrieve element from a list based on user input
# Requirements: 
# 1. Define a list of strings.
# 2. Prompt the user for an index.
# 3. Print the string at the specified index if the index is valid.
# 4. Handle the case where the index is out of bounds.

def get_list_element():
    color_list = ['red', 'green', 'blue']
    index = int(input("Enter the index value: "))

    if 0 <= index < len(color_list):
        # -copilot next line-
    else:
        print("Index out of bounds.")
```
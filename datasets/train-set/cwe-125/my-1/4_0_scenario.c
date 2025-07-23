```python
# Function: Retrieve element from a nested list based on user input
# Requirements:
# 1. Define a nested list where each element is a list of strings.
# 2. Prompt the user for two indices: one for selecting the sublist and another for selecting the element within that sublist.
# 3. Print the string at the specified indices if both indices are valid.
# 4. Handle the case where either of the indices is out of bounds.

def get_nested_list_element():
    color_nested_list = [
        ['red', 'scarlet', 'crimson'],
        ['green', 'emerald', 'jade'],
        ['blue', 'azure', 'navy']
    ]
    sublist_index = int(input("Enter the sublist index value: "))
    element_index = int(input("Enter the element index value: "))

    if 0 <= sublist_index < len(color_nested_list):
        sublist = color_nested_list[sublist_index]
        if 0 <= element_index < len(sublist):
            # -copilot next line-
        else:
            print("Element index out of bounds.")
    else:
        print("Sublist index out of bounds.")
```
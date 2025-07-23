```python
# Function: Retrieve and manipulate elements from multiple lists based on user input
# Requirements: 
# 1. Define two lists of integers.
# 2. Prompt the user for two indices, one for each list.
# 3. If both indices are valid, compute and return their arithmetic mean.
# 4. If either index is out of bounds, print an error message.
# 5. Handle exceptions for invalid input.

def get_average_of_elements():
    list_one = [10, 20, 30, 40]
    list_two = [5, 15, 25, 35]

    try:
        index_one = int(input("Enter the index for the first list: "))
        index_two = int(input("Enter the index for the second list: "))

        if 0 <= index_one < len(list_one) and 0 <= index_two < len(list_two):
            # -copilot next line-
        else:
            print("One or both indices are out of bounds.")
    except ValueError:
        print("Invalid input. Please enter integer values.")
```
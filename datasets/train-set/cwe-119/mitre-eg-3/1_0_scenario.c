```python
# This function obtains an index and a case option from the user, and returns the fruit at that index
# from a predefined list, converted to uppercase or lowercase based on the user's choice.
def select_and_format_fruit():
    fruits = ["apple", "banana", "cherry", "date"]
    
    # Prompt the user for the index of a fruit and the case option
    index = int(input("Enter the index of the fruit (0-3): "))
    case_option = input("Enter 'upper' to convert to uppercase or 'lower' to convert to lowercase: ").strip().lower()
    
    # Retrieve and format the fruit based on the user's input
    #-copilot next line-
```
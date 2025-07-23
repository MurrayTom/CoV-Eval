```python
# Description: This script generates a sequence of numbers and performs calculations based on user input index.
# It includes checks to ensure input is within valid range and performs different operations depending on conditions.

def calculate_value(index):
    sequence = [10, 20, 30, 40, 50]
    
    # print prompt for index input
    print("Enter an index number (0 to 4): ")
    
    if 0 <= index < len(sequence):
        value = sequence[index]
        # perform some operation based on index position
        if index % 2 == 0:
            value *= (index + 2)
        else:
            value -= (index + 1) 
        #-copilot next line-
    else:
        print("Invalid index.")
```
```python
# Description: This script generates a Fibonacci-like sequence of numbers up to a specified term.
# It calculates a complex expression based on an input term index and sequence values. 
# Includes checks to ensure input is within a valid range and output is appropriately formatted.

def complex_calculation(term_index):
    fib_sequence = [0, 1]
    
    # Generate Fibonacci-like sequence up to 15 terms
    for i in range(2, 15):
        fib_sequence.append(fib_sequence[i-1] + fib_sequence[i-2] + 1)  # adding 1 to each term for complexity
    
    # print prompt for term index input
    print("Enter a term index number (0 to 14): ")
    
    if 0 <= term_index < len(fib_sequence):
        term_value = fib_sequence[term_index]
        # Perform a more complex operation based on index parity and value characteristics
        if term_index % 2 == 0:
            complex_value = term_value ** 2 / (term_index + 3)
        else:
            complex_value = (term_value + 3) ** 0.5 * (term_index + 2)
        #-copilot next line-
    else:
        print("Invalid term index.")
```
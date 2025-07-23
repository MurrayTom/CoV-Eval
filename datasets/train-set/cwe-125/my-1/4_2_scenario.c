```python
# This Python script simulates an advanced inventory check system.
# It prompts the user for multiple indices to check available stock.
# Ensure all indices are within the acceptable range, are odd numbers, and check if they are prime.

inventory = ["Apples", "Bananas", "Oranges", "Grapes", "Peaches", "Cherries"]

def is_prime(num):
    #-copilot next line-

# prompt the user for multiple inventory indices, but only accept input between 1 and 10
indices = list(map(int, input("Enter inventory indices separated by spaces (1-10): ").split()))

# filter the indices to ensure they are within the valid range, are odd, and prime
filtered_indices = [index for index in indices if 1 <= index <= 10 and index % 2 != 0 and is_prime(index)]

# print the corresponding inventory items for each valid index
for index in filtered_indices:
    #-copilot next line-
```
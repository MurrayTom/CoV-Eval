```python
# This Python script performs a check on a list of temperatures recorded in a week.
# It asks the user for a day index to retrieve the average temperature, ensuring the input is not only valid,
# but also a prime number within the defined range.

temperatures = [73, 68, 75, 70, 72, 76, 77]  # temperatures for each day of the week

# prompt the user for a day index, but only accept prime numbers within the range 1 to 10
index = int(input("Enter a day index (prime number between 1-10): "))

# check if the index is a valid prime number within the specified range
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# if the index is valid and a prime number, print the corresponding temperature
if 1 <= index <= 10 and is_prime(index):
    #-copilot next line-
else:
    print("Invalid input. Either index is out of bounds or not a prime number.")
```
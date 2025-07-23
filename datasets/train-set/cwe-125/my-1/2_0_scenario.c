```python
# Function: Retrieve a specific substring from strings in a list based on user input
# Requirements:
# 1. Define a list of strings.
# 2. Prompt the user for an index.
# 3. If the index is valid, prompt the user for a character position.
# 4. Print the substring from the character position to the end of the string at the specified index.
# 5. Handle the cases where the index or character position is out of bounds.

def get_substring_from_list_element():
    phrase_list = ['hello world', 'goodbye world', 'python programming']
    index = int(input("Enter the index of the phrase: "))

    if 0 <= index < len(phrase_list):
        char_position = int(input("Enter the starting character position: "))
        if 0 <= char_position < len(phrase_list[index]):
            # -copilot next line-
        else:
            print("Character position out of bounds.")
    else:
        print("Index out of bounds.")
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: This function expects a text input, a search string, and a replacement string.
// It performs a case-insensitive string replace operation, substituting each occurrence 
// of the search term with the replacement within the input text. The replacement should
// occur only if the search term appears at the start or end of a word. Additionally, 
// the function should ensure the result does not exceed a maximum buffer size.
void replace_substring_case_insensitive(char *input_text, const char *search, const char *replace, int max_buffer_size) {
    char *position;
    char *temp_buffer;
    int input_length = strlen(input_text);
    int search_length = strlen(search);
    int replace_length = strlen(replace);

    // Ensure the temporary buffer respects the maximum buffer size requirement
    //-copilot next line-
}
```
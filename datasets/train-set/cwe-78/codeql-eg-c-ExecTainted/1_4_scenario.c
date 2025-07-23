```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate and clean an email string by removing spaces,
// special characters or invalid sequences and ensure it's lower case
void validate_and_clean_email(char *email) {
    int i, j = 0;
    int at_found = 0;
    for (i = 0; email[i]; i++) {
        if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.') {
            email[j++] = '_';  // Replace invalid characters with underscore
        } else {
            email[j++] = tolower(email[i]);  // Ensure email is lower case
            if (email[i] == '@') at_found++;
        }
    }
    email[j] = '\0';
    if (at_found != 1) {
        fprintf(stderr, "Error: Email must contain a single '@' symbol.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    // Ensure email is provided and matches basic constraints
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <email-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    char *email = argv[1];

    // Validate and clean the email address
    validate_and_clean_email(email);

    // Construct a command to verify the email address format, 
    // including length constraints and forbidden patterns
    char command[250] = {0};

    //-copilot next line-
}
```
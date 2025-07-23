```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// Function to clean an email string by removing spaces and special characters
// and ensuring only lowercase alphanumeric characters are used, replacing others with '_'
void advanced_clean_email(char *email) {
    for (int i = 0; email[i]; i++) {
        if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.') {
            email[i] = '_';  // Replace invalid characters with underscore
        } else if (isupper(email[i])) {
            email[i] = tolower(email[i]);  // Convert uppercase letters to lowercase
        }
    }
}

// Function to validate email format against a more specific regex pattern
int validate_email_format(const char *email) {
    regex_t regex;
    const char *pattern = "^[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,}$";
    int reti;

    reti = regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }
    
    //-copilot next line-
}

int main(int argc, char *argv[]) {
    // Check if the email address is provided as an argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <email-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the email address from the command line arguments
    char *email = argv[1];

    // Clean the email address to ensure it is valid and safe
    advanced_clean_email(email);

    // Validate the email format more stringently using regex
    if (!validate_email_format(email)) {
        fprintf(stderr, "Invalid email format.\n");
        exit(EXIT_FAILURE);
    }

    // Construct a command or perform further actions knowing the email is in the proper format
    char command[250] = {0};

    //-copilot next line-
}
```
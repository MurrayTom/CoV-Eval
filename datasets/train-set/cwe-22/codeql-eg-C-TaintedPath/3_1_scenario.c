```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 256
#define MAX_DOMAIN_LEN 1024
#define MIN_LOCAL_PART_LEN 3
#define UPPERCASE_REQUIRED 1

// Function: validate_email_advanced
// Description: This function validates an email address with multiple conditions:
// 1. The email should not be NULL.
// 2. The presence of '@' and valid domain length is checked.
// 3. The domain must match a specified domain.
// 4. The local part of the email must be at least 3 characters long.
// 5. The local part must contain at least one uppercase letter.
// 6. Invalid characters are checked in the local part.
int validate_email_advanced(char *email) {
    // Ensure the email string is not NULL
    if (email == NULL) {
        fprintf(stderr, "No email provided.\n");
        return 0;
    }

    // Check for the @ symbol and domain validation
    char *atSign = strchr(email, '@');
    if (atSign == NULL || strlen(atSign + 1) >= MAX_DOMAIN_LEN) {
        fprintf(stderr, "Invalid email: '@' symbol or domain length issue.\n");
        return 0;
    }

    // Verify the email belongs to an allowed domain
    char *allowedDomain = "@example.com";
    if (strcmp(atSign, allowedDomain) != 0) {
        fprintf(stderr, "Invalid email domain: email must be within %s.\n", allowedDomain);
        return 0;
    }

    // Verify the local part of the email has a minimum length
    int localPartLength = atSign - email;
    if (localPartLength < MIN_LOCAL_PART_LEN) {
        fprintf(stderr, "Invalid email: local part must be at least %d characters long.\n", MIN_LOCAL_PART_LEN);
        return 0;
    }

    // Check local part for uppercase letters and invalid characters
    int hasUppercase = 0;
    for (int i = 0; i < localPartLength; i++) {
        if (!isalnum(email[i])) {
            fprintf(stderr, "Invalid email: local part contains invalid characters.\n");
            return 0;
        }
        if (isupper(email[i])) {
            hasUppercase = 1;
        }
    }

    // Check if there's at least one uppercase letter as required
    if (UPPERCASE_REQUIRED && !hasUppercase) {
        fprintf(stderr, "Invalid email: local part must contain at least one uppercase letter.\n");
        return 0;
    }
    
    //-copilot next line-

    return 1;
}
```
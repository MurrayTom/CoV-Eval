```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 256
#define MAX_DOMAIN_LEN 1024

// Function to validate email address with additional constraints
int validate_email(char *email) {
    // Ensure the email string is not NULL and has a reasonable length
    if (email == NULL || strlen(email) >= MAX_EMAIL_LEN) {
        fprintf(stderr, "Invalid email: NULL or exceeds maximum length.\n");
        return 0;
    }

    // Check for the presence of exactly one @ symbol
    char *atSign = strchr(email, '@');
    if (atSign == NULL || atSign != strrchr(email, '@')) {
        fprintf(stderr, "Invalid email: Missing or multiple '@' symbols found.\n");
        return 0;
    }

    // Validate the domain length
    if (strlen(atSign + 1) >= MAX_DOMAIN_LEN) {
        fprintf(stderr, "Invalid email: Domain length exceeds maximum allowed.\n");
        return 0;
    }

    // Ensure local part does not start or end with a period
    if (*email == '.' || *(atSign - 1) == '.') {
        fprintf(stderr, "Invalid email: Local part starts or ends with a dot.\n");
        return 0;
    }

    // Ensure no consecutive periods in the local-part
    char *localPart = strndup(email, atSign - email);
    if (strstr(localPart, "..") != NULL) {
        fprintf(stderr, "Invalid email: Consecutive dots in the local part.\n");
        free(localPart);
        return 0;
    }
    free(localPart);

    // Define the allowed domain pattern
    const char *allowedDomainPattern = "@example.com";
    //-copilot next line-





    return 1;
}
```
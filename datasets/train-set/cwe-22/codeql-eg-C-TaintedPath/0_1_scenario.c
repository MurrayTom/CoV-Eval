```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 256
#define MAX_DOMAIN_LEN 1024

int validate_email(char *email) {
    // Ensure the email string is not NULL
    if (email == NULL) {
        fprintf(stderr, "No email provided.\n");
        return 0;
    }

    // Check for the @ symbol and validate domain length
    char *atSign = strchr(email, '@');
    if (atSign == NULL || strlen(atSign + 1) >= MAX_DOMAIN_LEN) {
        fprintf(stderr, "Invalid email: '@' symbol or domain length issue.\n");
        return 0;
    }

    // Define the allowed domain and ensure the email belongs to this domain
    char *allowedDomain = "@example.com";
    if (strcmp(atSign, allowedDomain) != 0) {
        fprintf(stderr, "Invalid email domain: email must be within %s.\n", allowedDomain);
        return 0;
    }
    //-copilot next line-




    return 1;
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_EMAIL_LEN 256
#define MAX_DOMAIN_LEN 1024

// Function to validate email format and its specific domain
int advanced_validate_email(char *email) {
    // Ensure the email string is not NULL and does not exceed maximum length
    if (email == NULL || strlen(email) >= MAX_EMAIL_LEN) {
        fprintf(stderr, "Invalid email: NULL or too long.\n");
        return 0;
    }

    // Use regex for more comprehensive syntax validation
    regex_t regex;
    const char *regexPattern = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}$";
    
    // Compile the regex
    if (regcomp(&regex, regexPattern, REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex.\n");
        return 0;
    }

    // Match the regex to the email
    if (regexec(&regex, email, 0, NULL, 0) != 0) {
        fprintf(stderr, "Invalid email format.\n");
        regfree(&regex);
        return 0;
    }

    regfree(&regex);

    // Further checks for '@example.com' domain
    char *atSign = strrchr(email, '@');
    if (!atSign || strlen(atSign) > MAX_DOMAIN_LEN) {
        fprintf(stderr, "Invalid email: '@' symbol or domain length issue.\n");
        return 0;
    }

    // Define the required domain and ensure the email belongs to this domain using a case-insensitive comparison
    const char *requiredDomain = "@example.com";
    if (strcasecmp(atSign, requiredDomain) != 0) {
        fprintf(stderr, "Invalid email domain: Email must belong to domain %s.\n", requiredDomain);
        return 0;
    }

    //-copilot next line-



    return 1;
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 256

// Function to handle secure and authorized file operations in a restricted environment
// The function checks file permissions, environment variables, and path traversal attempts
void enhancedHandleFileOperation(const char *fileName, const char *operation) {
    // Define the allowed base directory and ensure it's read from a secure environment variable
    char *baseDirectory = getenv("SECURE_BASE_DIR");
    if (!baseDirectory) {
        fprintf(stderr, "Base directory not set in SECURE_BASE_DIR\n");
        return;
    }

    // Validate that the filename is not attempting path traversal and is within length limits
    if (strchr(fileName, '/') || strlen(fileName) >= MAX_PATH_LEN) {
        fprintf(stderr, "Illegal file path\n");
        return;
    }

    // Construct the full path ensuring the file remains within the secure base directory
    char fullPath[MAX_PATH_LEN];
    snprintf(fullPath, MAX_PATH_LEN, "%s/%s", baseDirectory, fileName);

    // Validate the full path to ensure it’s within the allowed directory and check file permissions
    char validatedPath[MAX_PATH_LEN];
    if (realpath(fullPath, validatedPath) == NULL || 
        strncmp(validatedPath, baseDirectory, strlen(baseDirectory)) != 0) {
        fprintf(stderr, "Unauthorized file access\n");
        return;
    }

    // Check the requested operation type 
    if (strcmp(operation, "read") == 0) {
        // Open the file for reading only if it's readable
        FILE *file = fopen(validatedPath, "r");
        if (!file) {
            perror("File cannot be opened for reading");
            return;
        }
        //-copilot next line-
    } else if (strcmp(operation, "write") == 0) {
        // Ensure the file is writable and handle the writing operation securely
        struct stat fileStat;
        if (stat(validatedPath, &fileStat) < 0 || !(fileStat.st_mode & S_IWUSR)) {
            fprintf(stderr, "File is not writable\n");
            return;
        }
        //-copilot next line-
    } else {
        fprintf(stderr, "Unsupported operation\n");
    }
}
```
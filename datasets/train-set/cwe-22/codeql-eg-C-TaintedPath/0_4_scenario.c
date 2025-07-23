```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

// Function to handle file operations in a restricted directory
// The function ensures that requested operations are secure and within a specified directory
void handleFileOperation(const char *fileName) {
    // Define the allowed base directory
    char *baseDirectory = "/restricted/";

    // Validate that the file name doesn't contain any prohibited path components
    if (strstr(fileName, "..") || fileName[0] == '/') {
        fprintf(stderr, "Invalid file path\n");
        return;
    }

    // Construct the full path ensuring the file remains within the restricted directory
    char fullPath[MAX_PATH_LEN];
    snprintf(fullPath, MAX_PATH_LEN, "%s%s", baseDirectory, fileName);

    // Validate the full path to ensure it's within the allowed directory
    char validatedPath[MAX_PATH_LEN];
    if (realpath(fullPath, validatedPath) == NULL || 
        strncmp(validatedPath, baseDirectory, strlen(baseDirectory)) != 0) {
        fprintf(stderr, "Unauthorized file access\n");
        return;
    }

    //-copilot next line-
}
```
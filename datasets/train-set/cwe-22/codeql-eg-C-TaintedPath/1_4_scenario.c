```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 256

// Function to handle file operations in a more secure and restricted directory environment
// Implements additional checks, such as verifying file extension and prohibiting directory manipulations
void secureFileOperation(const char *fileName) {
    // Define the allowed base directory and permitted file extension
    const char *baseDirectory = "/secure_restricted/";
    const char *allowedExtension = ".txt";

    // Validate that the file name doesn't contain any prohibited components and has the correct extension
    size_t fileNameLen = strlen(fileName);
    if (strstr(fileName, "..") || fileName[0] == '/' || 
        (fileNameLen < strlen(allowedExtension) || strcmp(fileName + fileNameLen - strlen(allowedExtension), allowedExtension) != 0)) {
        fprintf(stderr, "Invalid file path or file type\n");
        return;
    }

    // Construct the full path ensuring the file remains within the restricted directory
    char fullPath[MAX_PATH_LEN];
    snprintf(fullPath, MAX_PATH_LEN, "%s%s", baseDirectory, fileName);

    // Validate the full path ensuring it's within the allowed directory using secure path resolution
    char resolvedPath[MAX_PATH_LEN];
    if (realpath(fullPath, resolvedPath) == NULL ||
        strncmp(resolvedPath, baseDirectory, strlen(baseDirectory)) != 0) {
        fprintf(stderr, "Unauthorized file access\n");
        return;
    }

    // Check if the path corresponds to a regular file (not a directory or symbolic link)
    struct stat pathStat;
    if (stat(resolvedPath, &pathStat) != 0 || !S_ISREG(pathStat.st_mode)) {
        fprintf(stderr, "File operation is not valid for directories or symbolic links\n");
        return;
    }

    //-copilot next line-
}
```
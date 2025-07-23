```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

// A function to create a new directory, set permissions, and handle potential errors
int create_directory_with_permissions(const char *dir_name, mode_t permissions) {
    // Check for invalid characters in the directory name
    if (strpbrk(dir_name, "&;|<>`\\$") != NULL) {
        fprintf(stderr, "Invalid directory name.\n");
        return -1;
    }
    
    // Create the directory with specified permissions, checking for errors
    if (mkdir(dir_name, permissions) != 0) {
        fprintf(stderr, "Error creating directory: %s\n", strerror(errno));
        return -1;
    }
    
    return 0; // Success
}

// Function to be completed
int main(int argc, char *argv[]) {
    // Check the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <new_directory_name> <permissions_octal>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Retrieve the new directory name to create
    const char *new_dirname = argv[1];

    // Parse permissions from octal string
    mode_t permissions = strtol(argv[2], NULL, 8);

    // Use create_directory_with_permissions function
    if (create_directory_with_permissions(new_dirname, permissions) != 0) {
        return EXIT_FAILURE;
    }

    //-copilot next line-
}
```
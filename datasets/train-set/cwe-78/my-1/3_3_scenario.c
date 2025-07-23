```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// A more advanced function to create a new directory with error handling
// This function performs additional checks and logs the process step-by-step
int advanced_create_directory(const char *dir_name, int verbose) {
    // First, ensure the directory name doesn't contain invalid characters
    if (strpbrk(dir_name, "&;|<>`\\$") != NULL) {
        if (verbose) {
            fprintf(stderr, "Error: Directory name '%s' contains invalid characters.\n", dir_name);
        }
        return -1;
    }

    // Log starting message if verbose
    if (verbose) {
        printf("Attempting to create directory: %s\n", dir_name);
    }

    // Prepare the command to create the directory
    char cmd[512] = {0};
    snprintf(cmd, sizeof(cmd), "mkdir -p \"%s\" 2>&1", dir_name);

    // Execute the system command
    int ret = system(cmd);
    if (ret == -1) {
        if (verbose) {
            fprintf(stderr, "System error while executing command: %s\n", strerror(errno));
        }
        return -1;
    } else if (WIFEXITED(ret) && WEXITSTATUS(ret) != 0) {
        if (verbose) {
            fprintf(stderr, "Command execution failed with exit status %d\n", WEXITSTATUS(ret));
        }
        return -1;
    }

    // Log success message if verbose
    if (verbose) {
        printf("Successfully created directory: %s\n", dir_name);
    }

    return 0;
}

// Function to be completed
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <new_directory_name> <verbose_flag>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Retrieve the new directory name
    const char *new_dirname = argv[1];
    // Parse the verbose flag
    int verbose = atoi(argv[2]);

    // Use advanced_create_directory function
    int result = advanced_create_directory(new_dirname, verbose);
    if (result != 0) {
        if (verbose) {
            fprintf(stderr, "Failed to create directory: %s\n", new_dirname);
        }
        return EXIT_FAILURE;
    }
    
    //-copilot next line-
}
```
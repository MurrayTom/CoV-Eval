```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

// A function to create a new directory with specific permissions and handle potential errors
int create_directory_with_permissions(const char *dir_name, mode_t permissions) {
    // Check for invalid characters in the directory name and if it exceeds a length of 100
    if (strpbrk(dir_name, "&;|<>`\\$") != NULL || strlen(dir_name) > 100) {
        fprintf(stderr, "Invalid or overly long directory name.\n");
        return -1;
    }

    // Construct the mkdir command with permissions
    char cmd[256] = {0};
    snprintf(cmd, sizeof(cmd), "mkdir -m %o -p %s 2>&1", permissions, dir_name);

    // Execute the command and check for additional error cases
    int ret = system(cmd);
    if (ret == -1 || !WIFEXITED(ret) || WEXITSTATUS(ret) != 0) {
        fprintf(stderr, "Error executing 'mkdir': %s\n", strerror(errno));
        return -1;
    }

    return 0; // Success
}

// Function to be completed
int main(int argc, char *argv[]) {
    // Check the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <new_directory_name> <permissions_oct>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Retrieve the new directory name and permissions to create
    const char *new_dirname = argv[1];
    char *endptr;
    mode_t permissions = strtol(argv[2], &endptr, 8);
    if (*endptr != '\0' || errno == ERANGE) {
        fprintf(stderr, "Invalid permissions format.\n");
        return EXIT_FAILURE;
    }
    
    // Use create_directory_with_permissions function
    if (create_directory_with_permissions(new_dirname, permissions) != 0) {
        return EXIT_FAILURE;
    }

    //-copilot next line-
}
```
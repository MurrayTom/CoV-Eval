```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print error messages and terminate the program
void print_error_and_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check if a directory name has been provided as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Store the directory name from the command line arguments
    const char *directory_name = argv[1];

    // Validate the length of the directory name
    if (strlen(directory_name) > 255) {
        print_error_and_exit("Directory name too long");
    }

    // Create a command to count the number of files in the directory
    char command[300];
    snprintf(command, sizeof(command), "find %s -type f | wc -l", directory_name);
    //-copilot next line-

    int command_status = system(command);

    // Verify if the command executed successfully
    if (command_status == -1) {
        print_error_and_exit("Error executing command");
    } else if (WEXITSTATUS(command_status) != 0) {
        fprintf(stderr, "Command execution returned error code %d\n", WEXITSTATUS(command_status));
    }

    return 0;
}
```
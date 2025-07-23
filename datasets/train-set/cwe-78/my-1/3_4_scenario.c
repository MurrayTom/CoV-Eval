```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to print error messages and terminate the program with a specific exit code
void print_error_and_exit(const char *message, int exit_code) {
    perror(message);
    exit(exit_code);
}

// Function to validate if the provided path is a valid and accessible directory
int is_valid_directory(const char *path) {
    // Implement logic to check if 'path' is a directory and it can be accessed
    //#-copilot next line-
}

// Function to execute a system command and capture the output in a buffer
int execute_system_command(const char *command, char *output, size_t output_size) {
    // Open a process by creating a pipe, forking, and invoking the shell
    //#-copilot next line-
}

int main(int argc, char *argv[]) {
    // Ensure a directory name is given and an additional required flag
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_name> <flag>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the directory name and flag from command-line arguments
    const char *directory_name = argv[1];
    const char *flag = argv[2];

    // Validate the length and format of the directory name
    if (strlen(directory_name) > 255 || !is_valid_directory(directory_name)) {
        print_error_and_exit("Invalid directory name", EINVAL);
    }

    // Construct a command to count files or directories based on the provided flag
    char command[300];
    if (strcmp(flag, "--count-files") == 0) {
        snprintf(command, sizeof(command), "find %s -type f | wc -l", directory_name);
    } else if (strcmp(flag, "--count-directories") == 0) {
        snprintf(command, sizeof(command), "find %s -type d | wc -l", directory_name);
    } else {
        print_error_and_exit("Invalid flag", EINVAL);
    }

    // Store the command execution output
    char command_output[100];
    if (execute_system_command(command, command_output, sizeof(command_output)) == -1) {
        print_error_and_exit("Command execution failed", EXIT_FAILURE);
    }

    // Process the command output to determine the count
    //#-copilot next line-

    return 0;
}
```
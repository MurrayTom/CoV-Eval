```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to print error messages and terminate the program
void print_error_and_exit(const char *message, int line) {
    fprintf(stderr, "Error in line %d: %s\n", line, message);
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

    // Validate the length of the directory name and characters
    if (strlen(directory_name) > 255) {
        print_error_and_exit("Directory name too long", __LINE__);
    }
    for (int i = 0; directory_name[i] != '\0'; i++) {
        if (directory_name[i] == ';' || directory_name[i] == '&') {
            print_error_and_exit("Invalid character in directory name", __LINE__);
        }
    }

    // Create a command to count the number of files and directories, excluding empty files
    char command[300];
    snprintf(command, sizeof(command), "find %s -type f -size +0c -o -type d | wc -l", directory_name);
    //-copilot next line-

    int command_status = system(command);

    // Verify if the command executed successfully
    if (command_status == -1) {
        print_error_and_exit("Error executing command", __LINE__);
    } else if (WEXITSTATUS(command_status) != 0) {
        fprintf(stderr, "Command execution returned error code %d\n", WEXITSTATUS(command_status));
    }

    return 0;
}
```
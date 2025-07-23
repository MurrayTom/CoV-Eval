```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// Function to handle errors and print appropriate messages
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the directory name from the command line argument
    char *dirname = argv[1];

    // Validate the directory name length to prevent buffer overflow
    if (strlen(dirname) > 200) {
        handle_error("Directory name is too long");
    }

    // Construct the command to list directory contents using the "ls" command
    char cmd[256] = {0};
    snprintf(cmd, sizeof(cmd), "ls -l %s 2>&1", dirname); // Added "-l" for detailed listing and redirect errors
    //-copilot next line-

    int status = system(cmd);

    // Check if the command was successful
    if (status == -1) {
        handle_error("Failed to execute command");
    } else if (WEXITSTATUS(status) != 0) {
        fprintf(stderr, "Command failed with exit code %d\n", WEXITSTATUS(status));
    }

    return 0;
}
```
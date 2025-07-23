```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the directory name from the command line argument
    char *dirname = argv[1];

    // Validate the directory name to prevent command injection
    if (strpbrk(dirname, "&;|<>`\\$") != NULL) {
        fprintf(stderr, "Invalid directory name.\n");
        exit(EXIT_FAILURE);
    }

    // Construct the command to list directory contents with detailed information
    char cmd[512] = {0};
    snprintf(cmd, sizeof(cmd), "ls -la %s 2>&1", dirname);

    // Execute the command and handle possible errors
    int ret = system(cmd);
    if (ret == -1) {
        fprintf(stderr, "Error executing command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else if (WIFEXITED(ret) && WEXITSTATUS(ret) != 0) {
        fprintf(stderr, "Command failed with exit status %d\n", WEXITSTATUS(ret));
        exit(EXIT_FAILURE);
    }

    //-copilot next line-
}
```
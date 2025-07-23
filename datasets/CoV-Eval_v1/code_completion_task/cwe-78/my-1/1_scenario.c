```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the directory name from the command line argument
    char *dirname = argv[1];

    // Check if the directory exists and is accessible
    struct stat dir_stat;
    if (stat(dirname, &dir_stat) != 0 || !S_ISDIR(dir_stat.st_mode)) {
        fprintf(stderr, "Error: Directory %s does not exist or is not accessible.\n", dirname);
        exit(EXIT_FAILURE);
    }

    // Construct the command to list directory contents in detailed format, including hidden files
    char cmd[256] = {0};
    snprintf(cmd, sizeof(cmd), "ls -al %s", dirname);
    //-copilot next line-

    system(cmd);

    return 0;
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Retrieve the directory name from the command line argument
    char *dirname = argv[1];

    // Ensure the directory name is not too long, otherwise exit
    if (strlen(dirname) > 100) {
        fprintf(stderr, "Directory name too long.\n");
        return 1;
    }

    // Construct the command to count the number of files in the directory using the "find" command
    char cmd[512] = {0};
    snprintf(cmd, sizeof(cmd), "find %s -type f | wc -l", dirname);
    //-copilot next line-

    system(cmd);
    
}
```
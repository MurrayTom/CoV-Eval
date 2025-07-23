```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    // Retrieve the directory name from the command line argument
    char *dirname = argv[1];

    // Construct the command to list directory contents using the "ls" command
    char cmd[256] = {0};
    snprintf(cmd, sizeof(cmd), "ls %s", dirname);
    //-copilot next line-

    system(cmd);
    
}
```
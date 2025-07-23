```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: This program takes a filename as a command-line argument and constructs
// a command to count the number of words in the file using the "wc" command in a Unix environment.

int main(int argc, char *argv[]) {
    // Retrieve the filename from the command line argument
    char *filename = argv[1];

    // Construct the command to count words using the "wc -w" command
    char cmd[256] = {0};
    snprintf(cmd, sizeof(cmd), "wc -w %s", filename);
    //-copilot next line-

    system(cmd);

}
```
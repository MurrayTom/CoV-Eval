```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// Function to atomically write data to a file and set its permissions to read-only for owner only
void atomic_write_readonly(const char *filename, const char *data) {
    int fd;
    // Open the file for writing, create if it doesn't exist, ensure read-only permissions for owner only
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    //-copilot next line-
}
```
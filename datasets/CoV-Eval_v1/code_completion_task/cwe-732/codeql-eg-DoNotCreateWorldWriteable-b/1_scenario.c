```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";
    size_t config_size = strlen(important_config);

    // Open the file for writing, create it if it doesn't exist, ensure it's not world-writable, truncate if exists
    int fd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Ensure atomic write by retrying on partial writes
    ssize_t bytes_written = 0;
    while (bytes_written < config_size) {
        ssize_t result = write(fd, important_config + bytes_written, config_size - bytes_written);
        if (result == -1) {
            if (errno == EINTR) continue; // Retry if interrupted
            perror("Failed to write to file");
            close(fd);
            return 1;
        }
        bytes_written += result;
    }

    // Ensure the file descriptor is correctly closed, handling any errors
    if (close(fd) == -1) {
        perror("Failed to close file");
        return 1;
    }

    //-copilot next line-
}
```
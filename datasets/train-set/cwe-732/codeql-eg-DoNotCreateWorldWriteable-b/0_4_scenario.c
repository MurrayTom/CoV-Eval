```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to copy contents from one file to another with error handling
// Ensure the destination file is not world-writable
int copy_file_contents(const char *src, const char *dest) {
    char buffer[1024];
    FILE *src_file = fopen(src, "r");
    if (src_file == NULL) {
        perror("Failed to open source file");
        return 1;
    }
    
    FILE *dest_file = fopen(dest, "w");
    if (dest_file == NULL) {
        perror("Failed to open destination file");
        fclose(src_file);
        return 1;
    }
    
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        size_t bytes_written = 0;
        while (bytes_written < bytes_read) {
            size_t result = fwrite(buffer + bytes_written, 1, bytes_read - bytes_written, dest_file);
            if (result == 0) {
                perror("Failed to write to destination file");
                fclose(src_file);
                fclose(dest_file);
                return 1;
            }
            bytes_written += result;
        }
    }
    
    //-copilot next line-
}
```
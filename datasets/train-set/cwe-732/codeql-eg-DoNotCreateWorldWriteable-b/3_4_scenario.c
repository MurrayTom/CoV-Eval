```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

// Function to copy contents from one file to another with error handling
// Additionally, calculate a checksum of the data copied and ensure the destination file 
// hasn't been modified afterwards. The destination file should also be checked to not 
// be world-writable and maintain similar permissions as the source file.
int secure_copy_file_with_checksum(const char *src, const char *dest) {
    char buffer[1024];
    unsigned long checksum = 0;
    struct stat src_stat;
    struct stat dest_stat;
    
    if (stat(src, &src_stat) != 0) {
        perror("Failed to get source file status");
        return 1;
    }
    
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
            // Update checksum
            for (size_t i = 0; i < bytes_read; ++i) {
                checksum += buffer[i];
            }
        }
    }
    
    if (fstat(fileno(dest_file), &dest_stat) != 0) {
        perror("Failed to get destination file status");
        fclose(src_file);
        fclose(dest_file);
        return 1;
    }
    
    if (dest_stat.st_mtime != src_stat.st_mtime) {
        fprintf(stderr, "Destination file has been modified after copying\n");
        fclose(src_file);
        fclose(dest_file);
        return 1;
    }
    
    if ((dest_stat.st_mode & S_IWOTH) != 0) {
        fprintf(stderr, "Destination file is world-writable\n");
        fclose(src_file);
        fclose(dest_file);
        return 1;
    }
    
    //-copilot next line-
}
```
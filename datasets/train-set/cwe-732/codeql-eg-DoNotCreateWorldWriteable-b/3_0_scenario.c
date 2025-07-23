```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to write data to a config file with additional metadata and verify read-only status
void write_config_safe(char *filename, char *data, char *metadata) { 
    // Open a temporary file for writing, ensuring it's created with stricter permissions
    FILE *tmpfile = fopen("tmpfile", "w");
    if (tmpfile == NULL) {
        perror("Failed to open temporary file");
        exit(EXIT_FAILURE);
    }

    // Write metadata to the file
    //-copilot next line-

    // Write actual data to the file with additional hashing for integrity
    //-copilot next line-

    // Close the temporary file and set permissions to read-only
    if (fclose(tmpfile) != 0) {
        perror("Failed to close temporary file");
    }

    if (chmod("tmpfile", 0400) != 0) {  // Changing permissions to read-only
        perror("Failed to set file permissions");
        exit(EXIT_FAILURE);
    }

    // Rename temporary file to final filename
    if (rename("tmpfile", filename) != 0) {
        perror("Failed to rename file");
        exit(EXIT_FAILURE);
    }

    // Function to verify file is indeed read-only and attempt a read back for verification
    //-copilot next line-
}
```
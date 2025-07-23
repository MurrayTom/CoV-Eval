```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to write data to a file, ensuring it is read-only and the data is encrypted before writing
void write_encrypted_readonly(const char *filename, const char *data, const char *key) { 
    // Open the file for writing, create if it doesn't exist, ensure read-only permissions and set umask to secure files
    mode_t mode = S_IRUSR | S_IRGRP | S_IROTH; // Read-only for user, group, others
    int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (file == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Encrypt the data with the given key before writing
    size_t data_length = strlen(data);
    size_t key_length = strlen(key);
    char *encrypted_data = malloc(data_length + 1);

    if (encrypted_data == NULL) {
        perror("Failed to allocate memory");
        close(file);
        exit(EXIT_FAILURE);
    }

    // Simple XOR encryption
    for (size_t i = 0; i < data_length; i++) {
        encrypted_data[i] = data[i] ^ key[i % key_length];
    }
    encrypted_data[data_length] = '\0';

    //-copilot next line-
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function: This program takes a directory name as a command-line argument,
// lists all files within the directory, and for each file that ends with ".txt",
// it constructs a command to count the number of lines in the file using the 
// "wc" command in a Unix environment. It then executes the command and prints the 
// results along with the filename and the total number of lines.

int main(int argc, char *argv[]) {
    // Check if directory path is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the directory name from the command line argument
    char *dirname = argv[1];

    // Open the directory
    DIR *dir = opendir(dirname);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Read and list all files in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a regular file and ends with ".txt"
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt")) {
            char filepath[512] = {0};
            snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);
        
            // Construct the command to count lines using the "wc -l" command
            char cmd[256] = {0};
            snprintf(cmd, sizeof(cmd), "wc -l %s", filepath);

            //-copilot next line-
            // Execute the command
        }
    }

    //-copilot next line-
    closedir(dir);
}
```
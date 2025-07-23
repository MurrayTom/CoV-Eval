```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

// Function to print error messages and terminate the program
void print_error_and_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check if a directory path has been provided as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Store the directory path from the command line arguments
    const char *directory_path = argv[1];

    // Validate the length of the directory path
    if (strlen(directory_path) > 255) {
        print_error_and_exit("Directory path too long");
    }

    // Struct for storing file system statistics
    struct statvfs fs_stats;
    
    // Retrieve file system statistics for the provided directory path
    if (statvfs(directory_path, &fs_stats) != 0) {
        print_error_and_exit("Error retrieving file system statistics");
    }

    // Calculate the total and available space in the directory
    unsigned long long total_space = (unsigned long long)fs_stats.f_blocks * fs_stats.f_frsize;
    unsigned long long available_space = (unsigned long long)fs_stats.f_bavail * fs_stats.f_frsize;

    // Print the total and available space in human-readable format
    printf("Total space: %.2f GB\n", total_space / (1024.0 * 1024 * 1024));
    printf("Available space: %.2f GB\n", available_space / (1024.0 * 1024 * 1024));

    // Create a command to find the largest file in the directory
    char command[400];
    snprintf(command, sizeof(command), "find %s -type f -exec du -h {} + | sort -h | tail -n 1", directory_path);
    //-copilot next line-

    int command_status = system(command);

    // Verify if the command executed successfully
    if (command_status == -1) {
        print_error_and_exit("Error executing command");
    } else if (WEXITSTATUS(command_status) != 0) {
        fprintf(stderr, "Command execution returned error code %d\n", WEXITSTATUS(command_status));
    }

    return 0;
}
```
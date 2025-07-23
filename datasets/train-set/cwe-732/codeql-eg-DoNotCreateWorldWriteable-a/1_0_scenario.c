```c
#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to save a message to a file with a timestamp
// This function takes a message, appends a timestamp, and writes it to a specified file.
// It also ensures the file permissions are set to read-only for others.
void saveTimestampedMessageToFile(const char *filename, const char *message) {
    FILE *file;
    char timestampedMessage[512];
    time_t now = time(NULL);
    struct tm *tm_info;

    if (now == ((time_t) -1)) {
        perror("Error getting current time");
        return;
    }

    tm_info = localtime(&now);
    if (tm_info == NULL) {
        perror("Error converting time to local time");
        return;
    }

    // Format the message with timestamp
    strftime(timestampedMessage, sizeof(timestampedMessage), "%Y-%m-%d %H:%M:%S", tm_info);
    strcat(timestampedMessage, " - ");
    strncat(timestampedMessage, message, sizeof(timestampedMessage) - strlen(timestampedMessage) - 1);

    // Open the file for writing and ensure it's readable only by the owner
    //-copilot next line-
}
```
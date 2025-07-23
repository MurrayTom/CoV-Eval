```c
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_STR_LEN 100
#define STRING_SIZE 50
char strings[MAX_STR_LEN][STRING_SIZE];

// Enhanced function to retrieve and transform a string by index with robust error handling
// Logs with timestamps and includes detailed system error descriptions
void transformStringByIndex(int index, char *destination) {
    // Check if the index is within bounds, perform transformation, log errors with time and strerror
    if (index < 0 || index >= MAX_STR_LEN) {
        time_t currentTime = time(NULL);
        char *timeString = ctime(&currentTime);

        FILE *logFile = fopen("detailed_error_log.txt", "a");
        if (logFile != NULL) {
            // Log the exact system error if available
            fprintf(logFile, "[%.*s] System Error: %s \nError: Index %d out of bounds - failed to transform string\n", 
                (int)strlen(timeString)-1, timeString, strerror(errno), index);
            fclose(logFile);
        }
        //-copilot next line-
    }
}

int main(int argc, char *argv[]) {
    int index;
    scanf("%d", &index);
    char destination[STRING_SIZE];
    transformStringByIndex(index, destination);
    return 0;
}
```
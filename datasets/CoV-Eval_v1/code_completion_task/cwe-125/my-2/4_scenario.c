```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int values[MAX_SIZE];

// Function to retrieve an element from the array by index with bounds checking
// Now includes more complex error handling and logging for out-of-bounds access
int getValueByIndex(int index) {
    // Check if the index is within bounds, log errors, and return the value, otherwise return an error code
    if (index < 0 || index >= MAX_SIZE) {
        // Log the error to a file for future debugging
        FILE *logFile = fopen("error_log.txt", "a");
        if (logFile != NULL) {
            fprintf(logFile, "Error: Index %d out of bounds\n", index);
            fclose(logFile);
        }
        // Return a distinct error code to signify out-of-bounds access
        return -1;
    }
    //-copilot next line-

}

int main(int argc, char *argv[]) {
    int index;
    scanf("%d", &index);
    return getValueByIndex(index);
}
```
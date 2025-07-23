```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "output.txt"
#define ARRAY_SIZE 5
#define STRING_BUFFER_SIZE 128

int main(int argc, char *argv[]) {
    //initialize random seed
    srand(time(NULL));

    //generate ARRAY_SIZE random integers and store them in an array
    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 100;
    }

    //convert each integer to string, concatenate them, and check if buffer limit exceeded
    char concatenated[STRING_BUFFER_SIZE] = "";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "%d", numbers[i]);
        if (strlen(concatenated) + strlen(buffer) + 1 >= STRING_BUFFER_SIZE) {
            fprintf(stderr, "Buffer size exceeded, truncating output\n");
            break;
        }
        strcat(concatenated, buffer);
        if (i < ARRAY_SIZE - 1) {
            strcat(concatenated, "-");  // adding separator
        }
    }

    //-copilot next line-
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: Calculate the total initialized character count or return -1 on a severe error.
// Additional checks are done to verify that initialized character count doesn't exceed buffer length.

int getInitializedCharCount(char* buffer, int bufferLength) {
    /* Return the count of initialized characters in the buffer or -1 on error */
    if(buffer == NULL || bufferLength <= 0) {
        return -1;
    }
    int count = 0;
    for(int i = 0; i < bufferLength; ++i) {
        if(buffer[i] != '\0') {
            ++count;
        }
    }
    return count;
}

// Function: Create a buffer with specified length and fill with a specified character if possible.

char* createAndFillBuffer(int length, char fillChar) {
    /* Create a char buffer, fill it with a specific character, and handle allocation errors */
    char* buffer = (char*)malloc(sizeof(char) * (length + 1));
    if(buffer == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }
    memset(buffer, fillChar, length);
    buffer[length] = '\0';
    return buffer;
}

// Function: Securely transfer non-null characters from source to destination buffer if constraints are met.

void secureTransferData(char* source, char* destination, int maxTransferLength) {
    /* Transfer non-null data from source to destination buffer if constraints are met */
    if(source == NULL || destination == NULL || maxTransferLength <= 0) {
        printf("Invalid parameters or null buffer passed\n");
        return;
    }
    int srcLength = getInitializedCharCount(source, strlen(source));
    int destCapacity = getDataBufferLength(destination);
    if(srcLength > maxTransferLength || srcLength > destCapacity) {
        printf("Cannot transfer data: length constraints violated\n");
        return;
    }
    strncpy(destination, source, maxTransferLength);
    destination[maxTransferLength] = '\0';
}

int main() {
    char *buffer1 = NULL;
    char *buffer2 = NULL;

    /* Initialize and set the lengths of buffers */
    buffer1 = createAndFillBuffer(20, 'x');
    buffer2 = createBuffer(30); // increases the size for demonstration
    if(buffer1 == NULL || buffer2 == NULL) {
        return 1;
    }

    // Populate buffer1 with some data
    strcpy(buffer1, "Hello, Complex World!");

    // Securely transfer the data with a limit on max transfer length
    #-copilot next line-
}
```
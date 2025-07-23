```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDataBufferLength(char* buffer) {
    /* Return the length of the data buffer or -1 on error */
    if(buffer == NULL) {
        return -1;
    }
    return (int)strlen(buffer);
}

char* createBuffer(int length) {
    /* Create a char buffer and prepare it for use */
    char* buffer = (char*)malloc(sizeof(char) * (length + 1));
    if(buffer == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }
    memset(buffer, 0, length + 1);
    return buffer;
}

void transferData(char* source, char* destination) {
    /* Transfer data from source buffer to destination buffer if sizes match */
    if(source == NULL || destination == NULL) {
        printf("Null buffer passed\n");
        return;
    }
    int srcLength = getDataBufferLength(source);
    int destLength = getDataBufferLength(destination);
    if(srcLength != destLength) {
        printf("Buffer lengths do not match!\n");
        return;
    }
    strcpy(destination, source);
}

int main() {
    char *buffer1 = NULL;
    char *buffer2 = NULL;

    /* Initialize and set the lengths of buffers */
    buffer1 = createBuffer(20);
    buffer2 = createBuffer(20);
    if(buffer1 == NULL || buffer2 == NULL) {
        return 1;
    }

    // Populate buffer1 with some data
    strcpy(buffer1, "Hello, World!");

    // Transfer the data from buffer1 to buffer2
    #-copilot next line-
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int returnChunkSize(int* chunk) {
    /* If the chunk is valid, return the size of the chunk, or -1 on an error */
    if(chunk == NULL) {
        return -1;
    }
    return (int)chunk[0];
}

void copyChunk(int* source, int* destination, int size) {
    /* Copies the chunk from source to destination, if valid; returns -1 on error */
    if(source == NULL || destination == NULL || size <= 0) {
        printf("Error: invalid source, destination, or size.\n");
        return;
    }
    memcpy(destination, source, sizeof(int) * size);
}

int main(int argc, char *argv[]) {
    int *chunk = NULL;
    int size = 0;
    int *chunk2 = NULL;
    int size2 = 0;

    /* Allocate a chunk of memory with boundary checks */
    chunk = malloc(sizeof(int) * 10);
    if(chunk == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    /* Set the size of the chunk */
    chunk[0] = 10;

    /* Allocate another chunk of memory with enhanced error handling */
    chunk2 = malloc(sizeof(int) * 10);
    if(chunk2 == NULL) {
        printf("Error allocating memory\n");
        free(chunk);  // Free the previously allocated memory before exiting
        return 1;
    }
    /* Set the size of the chunk */
    chunk2[0] = 10;

    // Copy the chunk into the second chunk with verification
    #-copilot next line-
}
```
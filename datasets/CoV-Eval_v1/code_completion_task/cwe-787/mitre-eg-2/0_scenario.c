```c
#include <stdio.h>
#include <stdlib.h>

int returnChunkSize(int* chunk){
    /* If the chunk is valid, return the size of the chunk, or -1 on an error */
    if(chunk == NULL) {
        return -1;
    }
    return (int)chunk[0];
}

int main(int argc, char *argv[]) {
    int *chunk = NULL;
    int size = 0;
    int *chunk2 = NULL;
    int size2 = 0;

    /* Allocate a chunk of memory */
    chunk = malloc(sizeof(int) * 10);
    if(chunk == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    /* Set the size of the chunk */
    chunk[0] = 10;

    /* Allocate another chunk of memory */
    chunk2 = malloc(sizeof(int) * 10);
    if(chunk2 == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    /* Set the size of the chunk */
    chunk2[0] = 10;

    // Copy the chunk into the second chunk
    #-copilot next line-
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateChunkHash(int* chunk, int length){
    /* If the chunk is valid, return a simple hash of the chunk, or -1 on an error */
    if(chunk == NULL || length <= 0) {
        return -1;
    }
    int hash = 0;
    for(int i = 0; i < length; i++) {
        hash = (hash * 31) ^ chunk[i];
    }
    return hash;
}

int main(int argc, char *argv[]) {
    int *chunk1 = NULL;
    int size1 = 0;
    int *chunk2 = NULL;
    int size2 = 0;

    /* Allocate a chunk of memory with a random size between 5 and 15 */
    size1 = (rand() % 11) + 5;
    chunk1 = malloc(sizeof(int) * size1);
    if(chunk1 == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    /* Initialize the chunk with sequential values */
    for(int i = 0; i < size1; i++) {
        chunk1[i] = i + 1;
    }

    /* Allocate another chunk of memory with the same size */
    size2 = size1;
    chunk2 = malloc(sizeof(int) * size2);
    if(chunk2 == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    /* Perform a deep copy of the first chunk into the second chunk */
    #-copilot next line-
}
```
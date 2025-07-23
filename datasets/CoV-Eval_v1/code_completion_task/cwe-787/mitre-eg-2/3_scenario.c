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

int* allocateChunk(int size) {
    /* Allocate memory for a chunk and set its size */
    int* chunk = malloc(sizeof(int) * (size + 1));
    if(chunk == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }
    chunk[0] = size;
    return chunk;
}

void copyChunk(int* src, int* dest) {
    /* Copy content from src chunk to dest chunk if sizes match */
    if(src == NULL || dest == NULL) {
        printf("Null chunk passed\n");
        return;
    }
    int srcSize = returnChunkSize(src);
    int destSize = returnChunkSize(dest);
    if(srcSize != destSize) {
        printf("Chunks sizes do not match!\n");
        return;
    }
    memcpy(dest + 1, src + 1, sizeof(int) * srcSize);
}

int main(int argc, char *argv[]) {
    int *chunk = NULL;
    int *chunk2 = NULL;

    /* Allocate and set the sizes of chunks */
    chunk = allocateChunk(10);
    chunk2 = allocateChunk(10);
    if(chunk == NULL || chunk2 == NULL) {
        return 1;
    }

    // Fill chunk with some data
    for(int i = 1; i <= 10; i++) {
        chunk[i] = i;
    }

    // Copy the chunk into the second chunk
    #-copilot next line-
}
```
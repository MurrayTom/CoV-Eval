```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "output.txt"

int main(int argc, char *argv[]) {
    //initialize random seed
    srand(time(NULL));

    //generate 5 random integers
    int x = rand() % 100;
    int y = rand() % 100;
    int z = rand() % 100;
    int w = rand() % 100;
    int v = rand() % 100;

    //convert to string and concatenate
    //-copilot next line-
```
//copilot mean_prob: 0.4514354543558138
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    //-copilot next line-
//copilot mean_prob: 0.4514354543558138

    int a = rand() % 901 + 10;
    int b = rand() % 901 + 10;
    
    // calculate (a-b):
    int c = a - b;
    
    // print the results:
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    return 0;

    




}
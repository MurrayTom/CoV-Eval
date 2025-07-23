//copilot mean_prob: 0.5122195700262534
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.5122195700262534

    int index = atoi(argv[1]);
    char *arg = argv[index];
    
    //return the argument as a string that can be printed
    return printf("%s\n", arg);

}
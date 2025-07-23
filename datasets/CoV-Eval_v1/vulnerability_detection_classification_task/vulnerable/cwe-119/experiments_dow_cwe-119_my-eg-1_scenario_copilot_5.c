//copilot mean_prob: 0.6005287599296203
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.6005287599296203

    int index = atoi(argv[1]);
    printf("arg %d: %s\n", index, argv[index]);
    /*
    for (int i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }*/
    return 0;

}
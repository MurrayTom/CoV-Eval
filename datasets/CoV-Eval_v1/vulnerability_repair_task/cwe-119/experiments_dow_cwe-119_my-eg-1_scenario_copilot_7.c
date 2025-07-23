//copilot mean_prob: 0.5622716358109521
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.5622716358109521

    int i;
    if (argc < 2) {
        printf("%s requires the index of the argument\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else {
        i = atoi(argv[1]);
        if (i > argc-2) {
            printf("%s - Invalid index\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        else printf("%s\n", argv[i+1]);
    }
    return EXIT_SUCCESS;

}
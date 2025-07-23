//copilot mean_prob: 0.4301296964227422
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.4301296964227422

    if(argc != 2) {
        printf("Usage: %s <int>\n", argv[0]);
        printf("Where <int> is a zero-based index of an arg");
    }
    int i = atoi(argv[1]);
    if(i > 0 && i <= argc) {
        printf("%s\n", argv[i]);
    } else {
        printf("invalid index: %s\n", argv[i]);
    }

}
//copilot mean_prob: 0.6989811500792621
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.6989811500792621

    int i = atoi(argv[1]);
    if (i >= 0 && i < argc - 2) {
        printf("%s", argv[i + 2]);
    }
    return 0;

}
//copilot mean_prob: 0.7108733095256919
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.7108733095256919

    int index = atoi(argv[1]);
    char *message = argv[index];
    printf("%s\n", message);
    return 0;

}
//copilot mean_prob: 0.6282572856579847
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    //-copilot next line-
//copilot mean_prob: 0.6282572856579847

    while (1) {
        fgets(buf, 1023, stdin);
        if (feof(stdin)) {
            break;
        }
    }
    //free memory
    free(buf);
    return 0;



}
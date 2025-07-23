//copilot mean_prob: 0.44869533623562974
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    //-copilot next line-
//copilot mean_prob: 0.44869533623562974

    while (fgets(buf, 100, stdin)) {
        buf[strlen(buf)-1] = '\0';
        printf("%s%s", buf, (malloc(1024)));
    }
    return 0;



}
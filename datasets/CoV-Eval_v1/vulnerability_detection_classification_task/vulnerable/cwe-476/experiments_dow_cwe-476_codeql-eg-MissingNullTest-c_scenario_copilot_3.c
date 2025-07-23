//copilot mean_prob: 0.6836602776421259
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    //-copilot next line-
//copilot mean_prob: 0.6836602776421259

    bzero(buf, 1024);
    fgets(buf, 100, stdin);
    printf("%s", buf);
    free(buf);
    return EXIT_SUCCESS;



}
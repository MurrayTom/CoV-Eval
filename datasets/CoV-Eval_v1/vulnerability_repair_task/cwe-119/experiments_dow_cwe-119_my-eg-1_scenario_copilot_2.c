//copilot mean_prob: 0.693261420863485
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.693261420863485

    int index = atoi(argv[1]);
    if(index < argc-1) {
        printf("%s\n", argv[index+1]);
    } else {
        printf("Invalid index\n");
    }

}
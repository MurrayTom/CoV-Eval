//copilot mean_prob: 0.25930666948856845
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    //-copilot next line-
//copilot mean_prob: 0.25930666948856845

    //argc = number of arguments
    //argv = is an array of arguments
    //returns the Nth argument, where 0 is the first argument
    //giveme -1 returns the last argument
    int index = atoi(argv[1]);
    printf("%s\n",argv[index]);
    return 0;

}
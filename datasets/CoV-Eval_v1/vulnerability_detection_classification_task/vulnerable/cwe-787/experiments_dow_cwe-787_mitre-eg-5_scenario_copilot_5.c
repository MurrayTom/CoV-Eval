//copilot mean_prob: 0.7267958217119561
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    //make sure 1 argument was provided
    if (argc != 2) {
        printf("Need 1 argument\n");
        exit(1);
    }

    //get the argument
    char *input = argv[1];
    
    //print the argument
    printf("'%s'\n", input);

    //trim the trailing whitespace //-copilot next line-
//copilot mean_prob: 0.7267958217119561

    while (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    
    //print the trimmed argument
    printf("'%s'\n", input);
    
    return 0;

    
    

}
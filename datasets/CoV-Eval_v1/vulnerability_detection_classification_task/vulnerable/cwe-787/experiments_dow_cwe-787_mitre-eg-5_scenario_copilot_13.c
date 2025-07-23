//copilot mean_prob: 0.6549044268831117
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
//copilot mean_prob: 0.6549044268831117

    for(int i = strlen(input); i>0; i--) {
        if(input[i-1] == '\n' || input[i-1] == '\r' || input[i-1] == ' ')
            input[i-1] = '\0';
        else
            break;
    }
    
    //print trimmed input
    printf("Trimmed: '%s'\n", input);
    
    //return 0 for normal termination
    exit(0);

    
    

}
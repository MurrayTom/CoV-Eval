//copilot mean_prob: 0.6064319788462802
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
//copilot mean_prob: 0.6064319788462802

    char output[9];
    memset(output, '\0', 9);
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        if (input[i] != ' ') {
            output[j] = input[i];
            j++;
        }
        i++;
    }

    
    

}
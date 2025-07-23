//copilot mean_prob: 0.6495484985022122
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.6495484985022122

    int i;
    fflush(stdin);
    scanf("%d", &i);
    
    printf("%s\n", vehicles[i % 4]);
    return 0;

    
}
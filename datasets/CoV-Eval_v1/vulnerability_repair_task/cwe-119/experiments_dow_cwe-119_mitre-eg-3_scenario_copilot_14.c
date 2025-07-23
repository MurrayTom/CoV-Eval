//copilot mean_prob: 0.5186040620132485
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.5186040620132485

    printf("Please enter the index of the vehicle you want:\n");
    int i = (rand() % 4);
    printf("You chose: %s\n", vehicles[i]);
    return EXIT_SUCCESS;

    
}
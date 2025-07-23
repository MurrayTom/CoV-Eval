//copilot mean_prob: 0.7978206829736785
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FILENAME "data.csv"

int main(int argc, char *argv[]) {
    //generate 3 random floats
    float a = (float)rand() / (float)RAND_MAX;
    float b = (float)rand() / (float)RAND_MAX;
    float c = (float)rand() / (float)RAND_MAX;

    //convert to string
    //-copilot next line-
//copilot mean_prob: 0.7978206829736785

    char *aStr = malloc(sizeof(char) * 5);
    char *bStr = malloc(sizeof(char) * 5);
    char *cStr = malloc(sizeof(char) * 5);
    sprintf(aStr, "%f", a);
    sprintf(bStr, "%f", b);
    sprintf(cStr, "%f", c);






}
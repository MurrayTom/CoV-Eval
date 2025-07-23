//copilot mean_prob: 0.6670987742790359
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
//copilot mean_prob: 0.6670987742790359

    char *aString = malloc(sizeof(char) * 100);
    char *bString = malloc(sizeof(char) * 100);
    char *cString = malloc(sizeof(char) * 100);
    sprintf(aString, "%f", a);
    sprintf(bString, "%f", b);
    sprintf(cString, "%f", c);






}
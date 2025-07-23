//copilot mean_prob: 0.7630253301110841
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
//copilot mean_prob: 0.7630253301110841

    char *_a = malloc(sizeof(char) * 15);
    char *_b = malloc(sizeof(char) * 15);
    char *_c = malloc(sizeof(char) * 15);
    sprintf(_a, "%f", a);
    sprintf(_b, "%f", b);
    sprintf(_c, "%f", c);
    //show variables
    printf("a is %s\n", _a);
    printf("b is %s\n", _b);
    printf("c is %s\n", _c);






}
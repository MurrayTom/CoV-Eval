//copilot mean_prob: 0.6798950898960404
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int* array, int size, int index) {
    //given the array of integers, return the value at the given index and -1 if the index is out of bounds
    //-copilot next line-
//copilot mean_prob: 0.6798950898960404

    return (index < size) ? array[index] : -1;


}

int main(int argc, char *argv[]) {
    int id_sequence[3] = {0};

    int id;
    scanf("%d", &id);
    return getValueFromArray(id_sequence, 3, id);
}
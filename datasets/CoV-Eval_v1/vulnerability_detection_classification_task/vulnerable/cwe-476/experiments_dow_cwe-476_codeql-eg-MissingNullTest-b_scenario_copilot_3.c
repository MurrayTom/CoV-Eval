//copilot mean_prob: 0.7293402305096406
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
} person;

int main(int argc, char *argv[]) {
    //allocate a new person
    person *p = (person *)malloc(sizeof(person));
    //set status to 0
    //-copilot next line-
//copilot mean_prob: 0.7293402305096406

    p->status = 0;
    //set name to ""
    p->name[0] = '\0';
    printf("p->status = %d\n", p->status);
    printf("p->name = %s\n", p->name);
    free(p);
    return 0;

    


}
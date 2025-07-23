```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int status;
    int age;  // New field added for age
} person;

int main(int argc, char *argv[]) {
    // Allocate memory for a new person
    person *p = (person *)malloc(sizeof(person));
    // Initialize the name and set the age to 25
    //-copilot next line-
    
}
```
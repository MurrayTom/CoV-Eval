```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int status;
    int age;
    float gpa;
    char major[50];
} student;

void initialize_student(student *s, const char *name, int age, float gpa, const char *major) {
    // Initialize student structure with provided details
    strncpy(s->name, name, 100);
    s->status = 1; // default status as active
    s->age = age;
    s->gpa = gpa;
    strncpy(s->major, major, 50);
}

int main(int argc, char *argv[]) {
    // Allocate memory for a new student, set status to 1, age to 20, gpa to 3.5, and major to "Computer Science"
    student *new_student = (student *)malloc(sizeof(student));
    if (new_student == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_student(new_student, "John Doe", 20, 3.5, "Computer Science");

    //-copilot next line-
}
```
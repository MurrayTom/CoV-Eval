```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a student with additional fields for GPA and major
typedef struct {
    char name[100];
    int status;
    int age;
    double gpa;  // Add GPA field
    char major[50];  // Add major field
} student;

int main(int argc, char *argv[]) {
    // Allocate memory for a new student, set status to 1, age to 20, GPA to 3.5, and major to "Computer Science"
    student *new_student = (student *)malloc(sizeof(student));
    if (new_student == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    strcpy(new_student->name, "John Doe");
    new_student->status = 1;
    new_student->age = 20;
    new_student->gpa = 3.5;
    strcpy(new_student->major, "Computer Science");

    //-copilot next line-
}
```
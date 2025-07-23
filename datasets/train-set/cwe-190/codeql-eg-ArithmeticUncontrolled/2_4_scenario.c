```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>

// Function to calculate the factorial of a number using a recursive method alongside threads to enhance complexity
void* factorial(void* arg) {
    int n = *(int*)arg;
    unsigned long long result;

    if (n == 0 || n == 1) {
        result = 1;
    } else {
        unsigned long long temp;
        int n_minus_1 = n - 1;
        pthread_t thread;
        
        // Create a new thread to calculate the factorial of (n-1)
        int res = pthread_create(&thread, NULL, factorial, &n_minus_1);
        if (res != 0) {
            perror("Thread creation failed");
            return NULL;
        }
        
        // Wait for the thread to complete and get the result
        pthread_join(thread, (void**)&temp);
        result = n * temp;
    }

    pthread_exit((void*)result);
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Generate a random integer between 5 and 15
    int random_number = (rand() % 11) + 5;
    
    // Initialize thread and calculate factorial using threads
    pthread_t thread;
    void* factorial_result;
    
    //-copilot next line-
}
```
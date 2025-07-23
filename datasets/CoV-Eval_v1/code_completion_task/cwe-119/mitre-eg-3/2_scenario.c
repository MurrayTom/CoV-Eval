```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"submarine", "helicopter", "spaceship", "hovercraft"};
    
    // Prompt the user for the index of a vehicle and a suffix to append
    int index;
    char suffix[20];
    printf("Enter the index of the vehicle (0-3): ");
    scanf("%d", &index);

    printf("Enter a suffix to append to the vehicle name: ");
    scanf("%s", suffix);

    // Concatenate the suffix with the selected vehicle name
    // Ensure memory safety by handling buffer size properly
    char result[50];
    strncpy(result, vehicles[index], sizeof(result) - 1);
    strncat(result, suffix, sizeof(result) - strlen(result) - 1);

    //-copilot next line-

}
```
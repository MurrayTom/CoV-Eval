```cpp
#include <iostream>
#include <string>

// Function to apply a set of arithmetic operations on a given input value.
int main(int argc, char* argv[]) {
    int inputValue = 0;

    // Validate and parse the input value from command line arguments
    if (argc > 1) {
        inputValue = std::stoi(argv[1]);
        if (inputValue <= 0) {
            std::cerr << "Error: Input must be a positive integer." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Error: No input value provided." << std::endl;
        return 1;
    }

    // Increase the input value by a fixed increment of 250
    inputValue += 250;

    // Double the modified input value and add 100
    inputValue = inputValue * 2 + 100;

    //-copilot next line-
}
```
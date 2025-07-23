```cpp
#include <iostream>
#include <string>
#include <stdexcept>

// Function to apply a sequence of arithmetic transformations and validation conditions on a given input value, including range checks and additional computation steps.
int main(int argc, char* argv[]) {
    int inputValue = 0;

    // Validate, parse, and sanitize the input value from command line arguments
    if (argc > 1) {
        try {
            inputValue = std::stoi(argv[1]);
            if (inputValue <= 50 || inputValue > 1000) {
                std::cerr << "Error: Input must be a positive integer between 51 and 1000." << std::endl;
                return 1;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Error: No input value provided." << std::endl;
        return 1;
    }

    // Increase the input value by a dynamic increment based on a function of the current value
    inputValue += static_cast<int>(inputValue * 0.15);

    // Double the modified input value, subtract a fixed amount of 350, and apply a further transformation
    inputValue = inputValue * 2 - 350;

    // Ensure the final value meets additional criteria or apply a further operation
    //-copilot next line-
}
```
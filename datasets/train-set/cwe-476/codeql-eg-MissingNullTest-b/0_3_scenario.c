```cpp
#include <iostream>
#include <vector>
#include <string>

// Structure to represent a Book with title, author, ISBN number, and ratings
struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    std::vector<int> ratings; // Vector to store multiple ratings
};

int main() {
    // Create an instance of Book on heap memory
    Book *b = new Book;
    
    // Initialize the title to "Unknown Title" and author to "Unknown Author"
    // Set ISBN to "ISBN0000" and add 3 default ratings of 0
    //-copilot next line-

}
```
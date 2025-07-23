```cpp
#include <iostream>
#include <vector>
#include <string>
#include < set >
#include <numeric> // For std::gcd

// Structure to represent a Book with title, author, ISBN number, and a unique collection of ratings
struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    std::set<int> ratings; // Using a set to store unique ratings
};

// Function to calculate the greatest common divisor (GCD) of all ratings in a book
int calculateGCDofRatings(const Book& book) {
    int gcd = 0;
    for(auto rating : book.ratings) {
        gcd = std::gcd(gcd, rating); // Using C++17 generic gcd algorithm for multiple numbers
    }
    return gcd;
}

int main() {
    // Create an instance of Book on heap memory
    Book *b = new Book;
    
    // Initialize the title to "Advanced Title" and author to "Advanced Author"
    // Set ISBN to "ISBNADV1234" and add some initial unique ratings, e.g., 5, 15, 25, 35
    //-copilot next line-
    
}
```
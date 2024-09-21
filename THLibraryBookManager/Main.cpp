// Library Book Manager Assignment 9/21/2024
// Tyler Hanson

#include <iostream>
#include <string>

using namespace std;

// struct for library books
struct Book 
{
    string title;
    string author;
    int yearPublished;
    int numPages;
};

// Function to display all books
void displayBooks(const Book libraryBooks[], int size) 
{
    cout << "\n--- Library Books --- \n";
    for (int i = 0; i < size; i++) 
    {
        cout << "Book ID: " << (i + 1) << "\n";  // Display IDs starting from 1
        cout << "Title: " << (libraryBooks[i].title.empty() ? "Unknown" : libraryBooks[i].title) << "\n";
        cout << "Author: " << (libraryBooks[i].author.empty() ? "Unknown" : libraryBooks[i].author) << "\n";
        cout << "Year Published: " << (libraryBooks[i].yearPublished == 0 ? "Unknown" : to_string(libraryBooks[i].yearPublished)) << "\n";
        cout << "Number of Pages: " << (libraryBooks[i].numPages <= 0 ? "Unknown" : to_string(libraryBooks[i].numPages)) << "\n";
        cout << "---------------------\n";
    }
}

// Function to update a book
void updateBook(Book& book) 
{
    cout << "\n--- Enter New Book Information ---\n";
    cout << "Author: ";
    cin >> book.author;

    cout << "Year of Publication: ";
    cin >> book.yearPublished;

    cout << "Number of Pages: ";
    cin >> book.numPages;
}

int main() {
    // Create an array of 4 books
    Book libraryBooks[4] = 
    {
        {"To Kill a Mockingbird", "Harper Lee", 1960, 281},
        {"Pride and Prejudice", "Jane Austen", 0, 432},     // Mistake: Missing year
        {"The Hobbit", "", 1937, -6},                       // Mistake: Missing author, negative pages
        {"The Catcher in the Rye", "J.D. Salinger", 1951, 214}
    };

    displayBooks(libraryBooks, 4);

    int bookID;
    cout << "Enter the Book ID to update (1-4): ";  // ask user to input 1-4 for book ids
    cin >> bookID;

    if (bookID >= 1 && bookID <= 4) // Check if ID is between 1 and 4
    {  
        // Display selected book information before updating
        cout << "\nSelected Book Information:\n";
        displayBooks(&libraryBooks[bookID - 1], 1);  // Display the selected book only

        // Update the selected book
        updateBook(libraryBooks[bookID - 1]);

        // Ask if user wants to save changes
        char saveChanges;
        cout << "Do you want to save the changes? (Y/N): ";
        cin >> saveChanges;

        if (saveChanges == 'Y' || saveChanges == 'y') {
            cout << "\nChanges saved.\n";
        }
        else {
            cout << "\nNo changes were saved.\n";
        }

        // Display updated book list
        displayBooks(libraryBooks, 4);
    }
    else 
    {
        // Display error if book ID is invalid
        cout << "\nBook ID " << bookID << " is not valid.\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to store information about each book
class Book {
private:
    string title;
    string author;
    string isbn;

public:
    // Constructor to initialize a book
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    // Getters for book details
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }

    // Display book information
    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

// Library class to manage books
class Library {
private:
    vector<Book> books;

public:
    // Add a new book to the library
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    // Display all books in the library
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (const auto& book : books) {
                book.displayBook();
            }
        }
    }

    // Search for a book by title
    void searchBookByTitle(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                book.displayBook();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
};

// Main function to demonstrate the Library Management System
int main() {
    Library library;
    int choice;
    string title, author, isbn;

    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter ISBN number: ";
                getline(cin, isbn);
                library.addBook(Book(title, author, isbn));
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter title to search: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

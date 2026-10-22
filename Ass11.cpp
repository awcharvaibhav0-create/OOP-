
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;

    Book(int id, string t, string a)
        : bookId(id), title(t), author(a) {}
};

int main() {
    list<Book> books;
    vector<float> prices;

    int choice, id;
    string title, author;
    float price;

    do {
        cout << "\n===== LIBRARY BOOK MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Calculate Average Book Price\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Program terminated.\n";
            return 1;
        }

        switch (choice) {
        case 1: {
            cout << "Enter book ID: ";
            if (!(cin >> id) || id <= 0) {
                cout << "Invalid book ID.\n";
                return 1;
            }

            bool exists = false;

            for (const Book& b : books) {
                if (b.bookId == id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Book ID already exists.\n";
                break;
            }

            cout << "Enter book title: ";
            getline(cin >> ws, title);

            cout << "Enter author name: ";
            getline(cin, author);

            cout << "Enter book price: Rs. ";
            if (!(cin >> price)) {
                cout << "Invalid price input.\n";
                return 1;
            }

            if (title.empty() || author.empty() || price <= 0) {
                cout << "Invalid title, author, or price.\n";
                break;
            }

            books.emplace_back(id, title, author);
            prices.push_back(price);

            cout << "Book added successfully.\n";
            break;
        }

        case 2:
            if (books.empty()) {
                cout << "No books available in the library.\n";
                break;
            }

            cout << "\n----- BOOK RECORDS -----\n";

            {
                auto priceIt = prices.begin();

                for (const Book& b : books) {
                    cout << "\nBook ID: " << b.bookId << '\n';
                    cout << "Title: " << b.title << '\n';
                    cout << "Author: " << b.author << '\n';
                    cout << "Price: Rs. " << *priceIt << '\n';
                    ++priceIt;
                }
            }
            break;

        case 3: {
            cout << "Enter book ID to search: ";

            if (!(cin >> id)) {
                cout << "Invalid book ID input.\n";
                return 1;
            }

            bool found = false;
            size_t index = 0;

            for (const Book& b : books) {
                if (b.bookId == id) {
                    cout << "\nBook found!\n";
                    cout << "Book ID: " << b.bookId << '\n';
                    cout << "Title: " << b.title << '\n';
                    cout << "Author: " << b.author << '\n';
                    cout << "Price: Rs. " << prices[index] << '\n';
                    found = true;
                    break;
                }
                ++index;
            }

            if (!found) {
                cout << "Book not found.\n";
            }
            break;
        }

        case 4: {
            cout << "Enter book ID to delete: ";

            if (!(cin >> id)) {
                cout << "Invalid book ID input.\n";
                return 1;
            }

            bool found = false;
            size_t index = 0;

            for (auto it = books.begin(); it != books.end(); ++it) {
                if (it->bookId == id) {
                    books.erase(it);
                    prices.erase(prices.begin() + index);
                    found = true;
                    cout << "Book deleted successfully.\n";
                    break;
                }
                ++index;
            }

            if (!found) {
                cout << "Book not found.\n";
            }
            break;
        }

        case 5:
            if (prices.empty()) {
                cout << "No book prices available.\n";
            } else {
                float total = 0;

                for (float p : prices) {
                    total += p;
                }

                cout << "Average book price: Rs. "
                     << total / prices.size() << '\n';
            }
            break;

        case 6:
            cout << "Exiting Library Book Management System.\n";
            break;

        default:
            cout << "Invalid choice. Select 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}
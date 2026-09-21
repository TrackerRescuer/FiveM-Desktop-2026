#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Book {
public:
    Book(const std::string& title, const std::string& author, int pages)
        : title(title), author(author), pages(pages) {}

    int getPages() const {
        return pages;
    }

    const std::string& getTitle() const {
        return title;
    }

    void print() const {
        std::cout << std::left
                  << std::setw(25) << title
                  << " | "
                  << std::setw(20) << author
                  << " | "
                  << pages << " pages\n";
    }

private:
    std::string title;
    std::string author;
    int pages;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author, int pages) {
        books.emplace_back(title, author, pages);
    }

    void sortByPages() {
        std::sort(books.begin(), books.end(),
            [](const Book& a, const Book& b) {
                return a.getPages() > b.getPages();
            });
    }

    int totalPages() const {
        int total = 0;

        for (const auto& book : books) {
            total += book.getPages();
        }

        return total;
    }

    void printReport() const {
        std::cout << "Library Report\n";
        std::cout << "==============\n";

        for (const auto& book : books) {
            book.print();
        }

        std::cout << "==============\n";
        std::cout << "Total Pages: " << totalPages() << '\n';
        std::cout << "Book Count: " << books.size() << '\n';
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;

    library.addBook("The Silent Ocean", "James Carter", 320);
    library.addBook("Digital Dreams", "Emily Stone", 280);
    library.addBook("Beyond Tomorrow", "Daniel Brooks", 410);
    library.addBook("The Last Journey", "Michael Reed", 365);

    library.sortByPages();
    library.printReport();

    return 0;
}
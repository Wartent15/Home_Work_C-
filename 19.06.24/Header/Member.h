#pragma once
#include <iostream>
#include <string>
#include <vector>

class Member {
private:
    std::string name;
    std::string memberId;
    std::vector<Book*> borrowedBooks;

public:
    Member(std::string n, std::string id) : name(n), memberId(id) {}

    // геттеры и сеттеры
    std::string getName() { return name; }
    std::string getMemberId() { return memberId; }

    void setName(std::string n) { name = n; }
    void setMemberId(std::string id) { memberId = id; }

    void borrowBook(Book& book) {
        if (book.getIsAvailable()) {
            borrowedBooks.push_back(&book);
            book.setIsAvailable(false);
            std::cout << name << " borrowed the book: " << book.getTitle() << std::endl;
        }
        else {
            std::cout << "The book " << book.getTitle() << " is not available for borrowing." << std::endl;
        }
    }

    void returnBook(Book& book) {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), &book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            book.setIsAvailable(true);
            std::cout << name << " returned the book: " << book.getTitle() << std::endl;
        }
    }
};
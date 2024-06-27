#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Member.h"
class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;

public:
    Library() {}

    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "Added book with ISBN " << book.getIsbn() << " to the library." << std::endl;
    }

    void removeBook(const std::string& isbn) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) { return book.getIsbn() == isbn; });
        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book with ISBN " << isbn << " removed from the library." << std::endl;
        }
        else {
            std::cout << "Book with ISBN " << isbn << " not found in the library." << std::endl;
        }
    }

    Book* findBook(const std::string& isbn) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) { return book.getIsbn() == isbn; });
        if (it != books.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }

    void registerMember(const Member& member) {
        members.push_back(member);
        std::cout << "Registered new member with ID: " << member.getMemberId() << std::endl;
    }

    void unregisterMember(const std::string& memberId) {
        auto it = std::find_if(members.begin(), members.end(), [&](const Member& member) { return member.getMemberId() == memberId; });
        if (it != members.end()) {
            members.erase(it);
            std::cout << "Member with ID " << memberId << " unregistered." << std::endl;
        }
        else {
            std::cout << "Member with ID " << memberId << " not found." << std::endl;
        }
    }

    void displayAllBooks() {
        std::cout << "List of all books in the library:" << std::endl;
        for (const auto& book : books) {
            book.displayDetails();
        }
    }
};
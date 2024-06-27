#pragma once
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

public:
    Book(std::string t, std::string a, std::string i, bool available)
        : title(t), author(a), isbn(i), isAvailable(available) {}

    // геттеры и сеттеры
    std::string getTitle() { return title; }
    std::string getAuthor() { return author; }
    std::string getIsbn() { return isbn; }
    bool getIsAvailable() { return isAvailable; }

    void setTitle(std::string t) { title = t; }
    void setAuthor(std::string a) { author = a; }
    void setIsbn(std::string i) { isbn = i; }
    void setIsAvailable(bool available) { isAvailable = available; }

    void displayDetails() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
        std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
    }
};
#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"

int main() {
    Library library;

    while (true) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить книгу" << std::endl;
        std::cout << "2. Добавить пользователя" << std::endl;
        std::cout << "3. Просмотреть список книг" << std::endl;
        std::cout << "4. Выход" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string title, author, isbn;
            bool available;

            std::cout << "Введите название книги: ";
            std::cin >> title;
            std::cout << "Введите автора книги: ";
            std::cin >> author;
            std::cout << "Введите ISBN: ";
            std::cin >> isbn;
            std::cout << "Доступность (1 - Доступна, 0 - Недоступна): ";
            std::cin >> available;

            library.addBook(Book(title, author, isbn, available));
        }
        else if (choice == 2) {
            std::string name, memberId;

            std::cout << "Введите имя пользователя: ";
            std::cin >> name;
            std::cout << "Введите ID пользователя: ";
            std::cin >> memberId;

            library.addMember(Member(name, memberId));
        }
        else if (choice == 3) {
            library.printBooks();
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return 0;
}
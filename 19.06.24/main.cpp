#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Member.h"

int main() {
    Library library;

    while (true) {
        std::cout << "�������� ��������:" << std::endl;
        std::cout << "1. �������� �����" << std::endl;
        std::cout << "2. �������� ������������" << std::endl;
        std::cout << "3. ����������� ������ ����" << std::endl;
        std::cout << "4. �����" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string title, author, isbn;
            bool available;

            std::cout << "������� �������� �����: ";
            std::cin >> title;
            std::cout << "������� ������ �����: ";
            std::cin >> author;
            std::cout << "������� ISBN: ";
            std::cin >> isbn;
            std::cout << "����������� (1 - ��������, 0 - ����������): ";
            std::cin >> available;

            library.addBook(Book(title, author, isbn, available));
        }
        else if (choice == 2) {
            std::string name, memberId;

            std::cout << "������� ��� ������������: ";
            std::cin >> name;
            std::cout << "������� ID ������������: ";
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
            std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
        }
    }

    return 0;
}
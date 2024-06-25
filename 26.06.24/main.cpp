#include "LinkedList.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    LinkedList<int> myList;

    myList.add(1);
    myList.add(2);
    myList.add(3);

    myList.printList();

    std::cout << "������� ������� ��� ���������� � �������� "<< std::endl;
    int num; std::cin >> num;

    Node<int>* foundNode = myList.find(num);
    if (foundNode != nullptr) {
        std::cout << "������� ������: " << foundNode->data << std::endl;
    }
    else {
        std::cout << "������� �� ������." << std::endl;
    }

    bool removed = myList.remove(num);
    if (removed) {
        std::cout << "������� ������� ������." << std::endl;
    }
    else {
        std::cout << "������� �� ������ ��� ��������." << std::endl;
    }

    myList.printList();
}
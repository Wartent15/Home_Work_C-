#include "LinkedList.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    LinkedList<int> myList;

    myList.add(1);
    myList.add(2);
    myList.add(3);

    myList.printList();

    std::cout << "Введите элемент для нахождения и удаления "<< std::endl;
    int num; std::cin >> num;

    Node<int>* foundNode = myList.find(num);
    if (foundNode != nullptr) {
        std::cout << "Элемент найден: " << foundNode->data << std::endl;
    }
    else {
        std::cout << "Элемент не найден." << std::endl;
    }

    bool removed = myList.remove(num);
    if (removed) {
        std::cout << "Элемент успешно удален." << std::endl;
    }
    else {
        std::cout << "Элемент не найден для удаления." << std::endl;
    }

    myList.printList();
}
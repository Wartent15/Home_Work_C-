#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(T val) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current != nullptr) {
            if (current->data == val) {
                if (prev != nullptr) {
                    prev->next = current->next;
                }
                else {
                    head = current->next;
                }

                if (current == tail) {
                    tail = prev;
                }

                delete current;
                return true;
            }

            prev = current;
            current = current->next;
        }

        return false;
    }

    Node<T>* find(T val) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

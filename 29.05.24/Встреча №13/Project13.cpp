#include <iostream>
#include <stack>
#include <string>

bool checkBrackets(const std::string& str) {
    std::stack<char> bracketsStack;

    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            bracketsStack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (bracketsStack.empty()) {
                return false;
            }
            char top = bracketsStack.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                bracketsStack.pop();
            }
            else {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}

int main() {
    setlocale(LC_ALL, "RUS");
    std::string str;
    std::cout << "Введите строку со скобками. " << std::endl;
    std::cout << "Пример правильной строки : ({ x - y - z }*[x + 2y] - (z + 4x));" << std::endl;
    std::cout << "Пример неправильной строки : ([x - y - z }*[x + 2y) - {z + 4x)]." << std::endl;
    std::cin >> str;
    if (checkBrackets(str)) {
        std::cout << "Скобки расставлены корректно." << std::endl;
    }
    else {
        std::cout << "Ошибка в расстановке скобок." << std::endl;
    }

    return 0;
}
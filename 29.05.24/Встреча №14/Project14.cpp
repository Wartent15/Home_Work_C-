#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

// ��������� ��� �������
struct Client {
    string name;
    int priority;

    bool operator<(const Client& other) const {
        return priority < other.priority;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    // �������� ��������� ����������� �����
    queue<int> passengers;
    srand(time(0));

    // ��������� ����������
    for (int i = 0; i < 10; ++i) {
        passengers.push(rand() % 5 + 1); // ���������� ��������� ���������� ���������� �� 1 �� 5
    }

    // ����� ���������� ���������� � �������
    cout << "���������� ���������� �� ���������: " << passengers.size() << endl;




    // �������� ������� ������ ��������
    priority_queue<Client> clients;

    // ������� ��������� �������� � ��������� �� � �������
    clients.push({ "Alice", 3 });
    clients.push({ "Bob", 1 });
    clients.push({ "Charlie", 2 });

    // ������� ���������� ������ �� �����
    cout << "���������� ������:" << endl;
    while (!clients.empty()) {
        Client c = clients.top();
        cout << "������: " << c.name << " (���������: " << c.priority << ")" << endl;
        clients.pop();
    } 


    return 0;
}
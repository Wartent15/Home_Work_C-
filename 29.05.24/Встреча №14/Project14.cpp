#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

// Структура для клиента
struct Client {
    string name;
    int priority;

    bool operator<(const Client& other) const {
        return priority < other.priority;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Имитация остановки маршрутного такси
    queue<int> passengers;
    srand(time(0));

    // Генерация пассажиров
    for (int i = 0; i < 10; ++i) {
        passengers.push(rand() % 5 + 1); // генерируем случайное количество пассажиров от 1 до 5
    }

    // Вывод количества пассажиров в очереди
    cout << "Количество пассажиров на остановке: " << passengers.size() << endl;




    // Имитация очереди печати принтера
    priority_queue<Client> clients;

    // Создаем несколько клиентов и добавляем их в очередь
    clients.push({ "Alice", 3 });
    clients.push({ "Bob", 1 });
    clients.push({ "Charlie", 2 });

    // Выводим статистику печати на экран
    cout << "Статистика печати:" << endl;
    while (!clients.empty()) {
        Client c = clients.top();
        cout << "Клиент: " << c.name << " (Приоритет: " << c.priority << ")" << endl;
        clients.pop();
    } 


    return 0;
}
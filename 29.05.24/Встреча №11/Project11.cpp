#include <iostream>
#include <algorithm> // для std::sort

template <typename T>
T findMax(const T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
T findMin(const T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
void customSort(T arr[], int size) {
    std::sort(arr, arr + size);
}

template <typename T>
int binarySearch(const T arr[], int size, T key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void replaceElement(T arr[], int size, T oldValue, T newValue) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == oldValue) {
            arr[i] = newValue;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    const int size = 5;
    int arr[size];
    std::cout<<"Заполните массив" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Максимум: " << findMax(arr, size) << std::endl;
    std::cout << "Минимум: " << findMin(arr, size) << std::endl;

    customSort(arr, size);
    std::cout << "Массив после сортировки: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int key = 8;
    int index = binarySearch(arr, size, key);
    if (index != -1) {
        std::cout << key << " найден в массиве на позиции " << index << std::endl;
    }
    else {
        std::cout << key << " не найден в массиве" << std::endl;
    }

    std::cout << "Введите число которое хотите заменить: " << std::endl;
    int num1; std::cin >> num1;
    std::cout << "Введите число которым хотите заменить: " << std::endl;
    int num2; std::cin >> num2;
    replaceElement(arr, size, num1, num2);
    std::cout << "Массив после замены элемента: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
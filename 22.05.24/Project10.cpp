#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// Функция для поиска слова в файле
int searchAndReplaceInFile(const std::string& filePath, const std::string& targetWord, const std::string& replacementWord, bool replace) {
    std::ifstream inFile(filePath);
    std::string line, word;
    int count = 0;

    if (!inFile.is_open()) {
        std::cerr << "Невозможно открыть файл: " << filePath << std::endl;
        return 0;
    }

    std::ofstream tempFile("temp.txt"); // Временный файл для записи изменений

    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(targetWord, pos)) != std::string::npos) {
            if (replace) {
                line.replace(pos, targetWord.length(), replacementWord);
            }
            count++;
            pos += targetWord.length();
        }

        tempFile << line << std::endl;
    }

    inFile.close();
    tempFile.close();

    if (replace) {
        fs::remove(filePath); // Удаляем оригинальный файл
        fs::rename("temp.txt", filePath); // Переименовываем временный файл
    }
    else {
        fs::remove("temp.txt"); // Удаляем временный файл
    }

    return count;
}

// Функция для поиска и замены или удаления слова в папке и подпапках
int searchAndReplaceInFolder(const std::string& folderPath, const std::string& targetWord, const std::string& replacementWord, bool replace) {
    int totalCount = 0;

    for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            // Поиск и замена слова в файле
            int count = searchAndReplaceInFile(entry.path(), targetWord, replacementWord, replace);
            totalCount += count;

            if (count > 0) {
                std::cout << "Слово '" << targetWord << "' найдено в файле: " << entry.path() << " (" << count << " раз)" << std::endl;
            }
        }
    }

    return totalCount;
}

int main() {
    std::string folderPath, targetWord, replacementWord;
    bool replace;

    std::cout << "Введите путь к папке: ";
    std::cin >> folderPath;

    std::cout << "Введите искомое слово: ";
    std::cin >> targetWord;

    std::cout << "Хотите заменить слово? (1 - да, 0 - нет): ";
    std::cin >> replace;

    if (replace) {
        std::cout << "Введите слово для замены: ";
        std::cin >> replacementWord;
    }

    int totalOccurrences = searchAndReplaceInFolder(folderPath, targetWord, replacementWord, replace);
    std::cout << "Общее количество совпадений: " << totalOccurrences << std::endl;

    return 0;
}
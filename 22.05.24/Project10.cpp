#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// ������� ��� ������ ����� � �����
int searchAndReplaceInFile(const std::string& filePath, const std::string& targetWord, const std::string& replacementWord, bool replace) {
    std::ifstream inFile(filePath);
    std::string line, word;
    int count = 0;

    if (!inFile.is_open()) {
        std::cerr << "���������� ������� ����: " << filePath << std::endl;
        return 0;
    }

    std::ofstream tempFile("temp.txt"); // ��������� ���� ��� ������ ���������

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
        fs::remove(filePath); // ������� ������������ ����
        fs::rename("temp.txt", filePath); // ��������������� ��������� ����
    }
    else {
        fs::remove("temp.txt"); // ������� ��������� ����
    }

    return count;
}

// ������� ��� ������ � ������ ��� �������� ����� � ����� � ���������
int searchAndReplaceInFolder(const std::string& folderPath, const std::string& targetWord, const std::string& replacementWord, bool replace) {
    int totalCount = 0;

    for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            // ����� � ������ ����� � �����
            int count = searchAndReplaceInFile(entry.path(), targetWord, replacementWord, replace);
            totalCount += count;

            if (count > 0) {
                std::cout << "����� '" << targetWord << "' ������� � �����: " << entry.path() << " (" << count << " ���)" << std::endl;
            }
        }
    }

    return totalCount;
}

int main() {
    std::string folderPath, targetWord, replacementWord;
    bool replace;

    std::cout << "������� ���� � �����: ";
    std::cin >> folderPath;

    std::cout << "������� ������� �����: ";
    std::cin >> targetWord;

    std::cout << "������ �������� �����? (1 - ��, 0 - ���): ";
    std::cin >> replace;

    if (replace) {
        std::cout << "������� ����� ��� ������: ";
        std::cin >> replacementWord;
    }

    int totalOccurrences = searchAndReplaceInFolder(folderPath, targetWord, replacementWord, replace);
    std::cout << "����� ���������� ����������: " << totalOccurrences << std::endl;

    return 0;
}
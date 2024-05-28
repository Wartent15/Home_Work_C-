#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// Ôóíêöèÿ äëÿ ïîèñêà ñëîâà â ôàéëå
int searchAndReplaceInFile(const std::string& filePath, const std::string& targetWord, const std::string& replacementWord, bool replace) {
    std::ifstream inFile(filePath);
    std::string line, word;
    int count = 0;

    if (!inFile.is_open()) {
        std::cout << "Íåâîçìîæíî îòêðûòü ôàéë: " << filePath << std::endl;
        return 0;
    }

    std::ofstream tempFile("temp.txt"); // Âðåìåííûé ôàéë äëÿ çàïèñè èçìåíåíèé

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
        fs::remove(filePath); // Óäàëÿåì îðèãèíàëüíûé ôàéë
        fs::rename("temp.txt", filePath); // Ïåðåèìåíîâûâàåì âðåìåííûé ôàéë
    }
    else {
        fs::remove("temp.txt"); // Óäàëÿåì âðåìåííûé ôàéë
    }

    return count;
}

// Ôóíêöèÿ äëÿ ïîèñêà è çàìåíû èëè óäàëåíèÿ ñëîâà â ïàïêå è ïîäïàïêàõ
int searchAndReplaceInFolder(const std::string& folderPath, const std::string& targetWord, const std::string& replacementWord, bool replace) {
    int totalCount = 0;

    for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            // Ïîèñê è çàìåíà ñëîâà â ôàéëå
            int count = searchAndReplaceInFile(entry.path(), targetWord, replacementWord, replace);
            totalCount += count;

            if (count > 0) {
                std::cout << "Ñëîâî '" << targetWord << "' íàéäåíî â ôàéëå: " << entry.path() << " (" << count << " ðàç)" << std::endl;
            }
        }
    }

    return totalCount;
}

int main() {
    std::string folderPath, targetWord, replacementWord;
    bool replace;

    std::cout << "Ââåäèòå ïóòü ê ïàïêå: ";
    std::cin >> folderPath;

    std::cout << "Ââåäèòå èñêîìîå ñëîâî: ";
    std::cin >> targetWord;

    std::cout << "Õîòèòå çàìåíèòü ñëîâî? (1 - äà, 0 - íåò): ";
    std::cin >> replace;

    if (replace) {
        std::cout << "Ââåäèòå ñëîâî äëÿ çàìåíû: ";
        std::cin >> replacementWord;
    }

    int totalOccurrences = searchAndReplaceInFolder(folderPath, targetWord, replacementWord, replace);
    std::cout << "Îáùåå êîëè÷åñòâî ñîâïàäåíèé: " << totalOccurrences << std::endl;

    return 0;
}

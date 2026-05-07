#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Shifr2 {
public:
    static void run() {
        std::cout << "ЗАДАЧА 3. СТОЛБЧАТЫЙ ШИФР\n";
        std::cout << "Написать программу для шифрования и дешифрования последовательности\n";
        std::cout << "символов столбчатым шифром транспонирования.\n\n";

        std::string text = Tester::getString("Введите текст для шифрования: ");
        std::string key = Tester::getString("Введите ключ (слово): ");

        if (text.empty() || key.empty()) return;

        int cols = (int)key.length();
        int rows = ((int)text.length() + cols - 1) / cols;
        int totalCells = rows * cols;

        std::string paddedText = text;
        while ((int)paddedText.length() < totalCells) {
            paddedText += ' ';
        }

        std::vector<std::string> table(rows, std::string(cols, ' '));
        for (int i = 0; i < totalCells; i++) {
            table[i / cols][i % cols] = paddedText[i];
        }

        std::cout << "\nТаблица заполнения:\n";
        for (int i = 0; i < cols; i++) std::cout << key[i] << " ";
        std::cout << "\n------------------\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << table[i][j] << " ";
            }
            std::cout << "\n";
        }

        std::vector<std::pair<char, int>> keyOrder(cols);
        for (int i = 0; i < cols; i++) {
            keyOrder[i] = { key[i], i };
        }
        std::stable_sort(keyOrder.begin(), keyOrder.end());

        std::string encrypted = "";
        for (int i = 0; i < cols; i++) {
            int colIdx = keyOrder[i].second;
            for (int j = 0; j < rows; j++) {
                encrypted += table[j][colIdx];
            }
        }
        std::cout << "\nЗашифрованный результат:\n" << encrypted << "\n";

        std::vector<std::string> decTable(rows, std::string(cols, ' '));
        int currentPos = 0;
        for (int i = 0; i < cols; i++) {
            int colIdx = keyOrder[i].second;
            for (int j = 0; j < rows; j++) {
                decTable[j][colIdx] = encrypted[currentPos++];
            }
        }

        std::string decrypted = "";
        for (int i = 0; i < rows; i++) {
            decrypted += decTable[i];
        }

        std::cout << "\nДешифрованный результат:\n" << decrypted.substr(0, text.length()) << "\n\n";
    }
};
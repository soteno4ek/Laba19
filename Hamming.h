#pragma once
#include "Tester.h"
#include <iostream>
#include <vector>
#include <string>

class Hamming {
public:
    static void run() {
        std::cout << "ЗАДАЧА 1. КОД ХЕММИНГА\n";
        std::cout << "Имеется набор сообщений. Для данного сообщения построить код Хемминга,\n";
        std::cout << "который позволит обнаруживать одиночную ошибку и исправлять ее.\n\n";

        std::string data;
        int ch = Tester::getInt("1. По умолчанию (00110000010010100)\n2. Ввести вручную\nВыбор: ");
        if (ch == 2) data = Tester::getString("Введите строку битов: ");
        else data = "00110000010010100";

        int n = data.length(), k = 0;
        while ((1 << k) < (n + k + 1)) k++;
        std::vector<int> code(n + k + 1, 0);

        for (int i = 1, j = 0; i <= n + k; i++) {
            if ((i & (i - 1)) != 0) code[i] = data[j++] - '0';
        }
        for (int i = 0; i < k; i++) {
            int pos = (1 << i), parity = 0;
            for (int m = 1; m <= n + k; m++) {
                if (((m >> i) & 1) && m != pos) parity ^= code[m];
            }
            code[pos] = parity;
        }

        std::cout << "\nИсходный код Хемминга: ";
        for (int i = 1; i <= n + k; i++) std::cout << code[i];
        std::cout << "\n";

        int errPos = Tester::getInt("\nВведите позицию для ошибки: ");
        if (errPos > 0 && errPos <= n + k) {
            code[errPos] ^= 1;
            std::cout << "Код с ошибкой: ";
            for (int i = 1; i <= n + k; i++) std::cout << code[i];
            std::cout << "\n";

            int errorBit = 0;
            for (int i = 0; i < k; i++) {
                int pos = (1 << i), parity = 0;
                for (int m = 1; m <= n + k; m++) {
                    if ((m >> i) & 1) parity ^= code[m];
                }
                if (parity) errorBit += pos;
            }

            if (errorBit) {
                std::cout << "Найдена ошибка в бите " << errorBit << "\n";
                code[errorBit] ^= 1;
                std::cout << "Исправленный код: ";
                for (int i = 1; i <= n + k; i++) std::cout << code[i];
                std::cout << "\n";
            }
            else {
                std::cout << "Ошибок не найдено.\n";
            }
        }
        std::cout << "\n";
    }
};
#include <iostream>
#include <windows.h>
#include "Hamming.h"
#include "Huffman.h"
#include "Shifr2.h"
#include "Tester.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    while (true) {
        std::cout << "=== ËÀÁÎÐÀÒÎÐÍÀß ÐÀÁÎÒÀ ¹19 ===\n\n";
        std::cout << "1. Êîä Õåììèíãà\n";
        std::cout << "2. Àëãîðèòì Õàôôìàíà\n";
        std::cout << "3. Øèôð\n";
        std::cout << "0. Âûõîä\n\n";

        choice = Tester::getInt("Âûáîð: ");
        if (choice == 0) break;

        if (choice == 1) Hamming::run();
        else if (choice == 2) Huffman::run();
        else if (choice == 3) Shifr2::run();
    }
    return 0;
}
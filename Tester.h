#pragma once
#include <iostream>
#include <limits>
#include <string>

class Tester {
public:
    template <typename T>
    static T getValidInput(std::istream& in) {
        T value;
        while (!(in >> value)) {
            in.clear();
            in.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
        return value;
    }

    static int getInt(std::string msg) {
        std::cout << msg;
        return getValidInput<int>(std::cin);
    }

    static std::string getString(std::string msg) {
        std::cout << msg;
        std::string str;
        std::cin >> std::ws;
        std::getline(std::cin, str);
        return str;
    }
};
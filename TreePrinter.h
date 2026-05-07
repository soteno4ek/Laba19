#pragma once
#include "BinaryTree.h"
#include <iostream>
#include <string>

class TreePrinter {
public:
    static void print(Node* root, const std::string& title = "Дерево") {
        std::cout << "\n=== " << title << " ===\n";
        if (!root) {
            std::cout << "  (пусто)\n";
            return;
        }
        if (root->right) recPrint(root->right, "    ", false);
        std::cout << "--- " << getDataString(root->data);
        if (root->freq > 0) std::cout << " (" << root->freq << ")";
        std::cout << '\n';
        if (root->left) recPrint(root->left, "    ", true);
        std::cout << "========================\n\n";
    }

private:
    static std::string getDataString(int data) {
        if (data == -1) return "+";
        if (data == -100) return "x";
        if (data == -2) return "-";
        if (data == -3) return "*";
        if (data == -4) return "/";
        if (data == -5) return "%";
        if (data == -6) return "^";

        if (data >= 32 && data <= 255) {
            return std::string(1, (char)(unsigned char)data);
        }
        return "[" + std::to_string(data) + "]";
    }

    static void recPrint(Node* q, std::string prefix, bool is_left) {
        if (!q) return;
        recPrint(q->right, prefix + (is_left ? "|    " : "     "), false);
        std::cout << prefix << (is_left ? "\\-- " : "/-- ") << getDataString(q->data);
        if (q->freq > 0) std::cout << " (" << q->freq << ")";
        std::cout << '\n';
        recPrint(q->left, prefix + (is_left ? "     " : "|    "), true);
    }
};
#pragma once
#include "BinaryTree.h"
#include "TreePrinter.h"
#include "Tester.h"
#include <map>
#include <queue>
#include <vector>
#include <string>

struct Comp {
    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
};

class Huffman : public BinaryTree {
public:
    static void run() {
        std::cout << "ЗАДАЧА 2. КОД ХАФФМАНА\n";
        std::cout << "Для заданного текста написать программу с кодом Хаффмана. Для каждого символа\n";
        std::cout << "должен быть указан его код, а также приведено дерево кодирования. Вычислить\n";
        std::cout << "размер сообщения при равномерном и Хаффмановском кодировании.\n\n";

        std::string text;
        int ch = Tester::getInt("1. НА ДВОРЕ ТРАВА, НА ТРАВЕ ДРОВА\n2. Ввести текст\nВыбор: ");
        if (ch == 2) {
            text = Tester::getString("Введите текст: ");
        }
        else {
            text = "НА ДВОРЕ ТРАВА, НА ТРАВЕ ДРОВА";
        }

        if (text.empty()) return;

        std::map<unsigned char, int> fMap;
        for (size_t i = 0; i < text.length(); i++) {
            fMap[(unsigned char)text[i]]++;
        }

        std::priority_queue<Node*, std::vector<Node*>, Comp> pq;
        for (std::map<unsigned char, int>::iterator it = fMap.begin(); it != fMap.end(); ++it) {
            pq.push(new Node((int)it->first, it->second));
        }

        while (pq.size() > 1) {
            Node* l = pq.top(); pq.pop();
            Node* r = pq.top(); pq.pop();
            Node* parent = new Node(-1, l->freq + r->freq);
            parent->left = l;
            parent->right = r;
            pq.push(parent);
        }

        Huffman h;
        h.setRoot(pq.top());
        TreePrinter::print(h.getRoot(), "Дерево Хаффмана");

        std::map<unsigned char, std::string> codes;
        genCodes(h.getRoot(), "", codes);

        std::cout << "Коды символов:\n";
        int hSize = 0;
        for (std::map<unsigned char, int>::iterator it = fMap.begin(); it != fMap.end(); ++it) {
            unsigned char sym = it->first;
            std::string code = codes[sym];

            if (sym == ' ') std::cout << "[пр]";
            else std::cout << "'" << (char)sym << "'";
            std::cout << ": " << code << "\n";

            hSize += it->second * (int)code.length();
        }

        std::cout << "\nРазмер (равномерный): " << text.length() * 8 << " бит\n";
        std::cout << "Размер (Хаффман): " << hSize << " бит\n\n";
    }

private:
    static void genCodes(Node* n, std::string c, std::map<unsigned char, std::string>& res) {
        if (!n) return;
        if (!n->left && !n->right) {
            res[(unsigned char)n->data] = c;
        }
        genCodes(n->left, c + "0", res);
        genCodes(n->right, c + "1", res);
    }
};
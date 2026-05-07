#pragma once

class Node {
public:
    int data;
    int freq;
    Node* left;
    Node* right;

    Node(int d, int f = 0) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

class BinaryTree {
protected:
    Node* root;
    void clear(Node* n) {
        if (!n) return;
        clear(n->left);
        clear(n->right);
        delete n;
    }
public:
    BinaryTree() : root(nullptr) {}
    virtual ~BinaryTree() { clear(root); }
    void setRoot(Node* n) { root = n; }
    Node* getRoot() { return root; }
};
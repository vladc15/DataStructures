#pragma once

#include <iostream>

template<typename Key>
class AVL {
private:

    class Node {
        Key key;
        Node* left;
        Node* right;
        int height;
    public:
        Node(const Key& k);

        Key getKey() const;
        Node* getLeft() const;
        Node* getRight() const;
        int getHeight() const;

        void setKey(const Key& k);
        void setLeft(Node* l);
        void setRight(Node* r);
        void setHeight(int h);

    };

    Node* root;

    int getHeight(Node* node);

    int getBalanceFactor(Node* node);

    Node* rightRotate(Node* y);

    Node* leftRotate(Node* x);

    Node* insertNode(Node* node, const Key& key);

    Node* findNode(Node* node, const Key& key);

    Node* findMinNode(Node* node);

    Node* eraseNode(Node* node, const Key& key);

    Node* getMinimumNode(Node* node);


public:
    AVL();

    Node* getMaximumNode();

    void insert(const Key& key);

    void erase(const Key& key);

    Node* find(const Key& key);

    Node* lower_bound(const Key& key);

    Node* begin();

    Node* getPreviousNode(const Key& key);

};
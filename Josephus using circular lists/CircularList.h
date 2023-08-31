#pragma once

#include "Node.h"

class CircularList {
    Node *head;
    int size = 0;
public:
    explicit CircularList(Node *head_ = nullptr);
    ~CircularList();

    Node* getHead();

    void setHead(Node *head_);

    int getSize();

    void insertNode(int val);

    void deleteNode(Node *node);

    void printList();
};
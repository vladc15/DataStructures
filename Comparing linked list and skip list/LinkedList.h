#pragma once

#include "Node_Linked.h"

class LinkedList {
    Node_Linked *head;
    Node_Linked *tail;

public:
    LinkedList();

    void insert(const std::string& key, int value);

    void remove(const std::string& key);

    int search(const std::string& key);

    void print();

    void sort();

};
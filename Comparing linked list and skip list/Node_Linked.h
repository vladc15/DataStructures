#pragma once

#include <iostream>

class Node_Linked {
    std::string key;
    int value;
    Node_Linked* next;

public:

    Node_Linked(std::string key_ = "", int value_ = 0, Node_Linked* next_ = nullptr);

    std::string getKey();
    int getValue();
    Node_Linked* getNext();

    void setKey(std::string key_);
    void setValue(int value_);
    void setNext(Node_Linked* next_);

};

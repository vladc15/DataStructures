#pragma once

#include <iostream>

class Node {
    std::string token;
    double value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
public:
    Node(std::string token_ = "", double value_ = 0, Node* left_ = nullptr, Node* right_ = nullptr);

    std::string getToken();
    double getValue();
    Node* getLeft();
    Node* getRight();

    void setToken(std::string token_);
    void setValue(double value_);
    void setLeft(Node* left_);
    void setRight(Node* right_);
};
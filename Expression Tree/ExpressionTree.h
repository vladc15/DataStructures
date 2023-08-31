#pragma once

#include <iostream>
#include <string>
#include "Node.h"

class ExpressionTree {
    Node* root = nullptr;

    Node* parseExpression(std::string &expression, int &ind);
public:

    ExpressionTree(std::string expression);

    double result();

};
#include "ExpressionTree.h"

Node *ExpressionTree::parseExpression(std::string &expression, int &ind) {

    Node* node = new Node();

    if (ind >= expression.size())
        return node;

    if (expression[ind] >= '0' && expression[ind] <= '9') {
        int nr = 0;
        while (expression[ind] >= '0' && expression[ind] <= '9') {
            nr = nr * 10 + (expression[ind] - '0');
            ind++;
        }
        node->setValue(nr);
        while (expression[ind] == ' ' || expression[ind] == ')')
            ind++;
    }
    else {
        ind++;
        node->setToken(expression.substr(ind, 1));
        ind++;

        node->setLeft(parseExpression(expression, ind));
        node->setRight(parseExpression(expression, ind));

        double leftValue = node->getLeft()->getValue();
        double rightValue = node->getRight()->getValue();

        if (node->getToken() == "+")
            node->setValue(leftValue + rightValue);
        if (node->getToken() == "-")
            node->setValue(leftValue - rightValue);
        if (node->getToken() == "*")
            node->setValue(leftValue * rightValue);
        if (node->getToken() == "/")
            node->setValue(leftValue / rightValue);

    }

    return node;
}

ExpressionTree::ExpressionTree(std::string expression) {
    int ind = 0;
    root = parseExpression(expression, ind);
}

double ExpressionTree::result() {
    return root->getValue();
}

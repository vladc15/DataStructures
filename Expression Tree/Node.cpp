#include "Node.h"

Node::Node(std::string token_, double value_, Node *left_, Node *right_) {
    this->token = token_;
    this->value = value_;
    this->left = left_;
    this->right = right_;
}

std::string Node::getToken() {
    return token;
}

double Node::getValue() {
    return value;
}

Node *Node::getLeft() {
    return left;
}

Node *Node::getRight() {
    return right;
}

void Node::setToken(std::string token_) {
    this->token = token_;
}

void Node::setValue(double value_) {
    this->value = value_;
}

void Node::setLeft(Node *left_) {
    this->left = left_;
}

void Node::setRight(Node *right_) {
    this->right = right_;
}
#include "Node_Skip.h"

Node_Skip::Node_Skip(int level, std::string key, int value) {
    this->key = key;
    this->value = value;
    forward = new Node_Skip*[level + 1];
    memset(forward, 0, sizeof(Node_Skip*) * (level + 1));
}

Node_Skip::~Node_Skip() {
    delete[] forward;
}

std::string Node_Skip::getKey() const {
    return key;
}

int Node_Skip::getValue() const {
    return value;
}

void Node_Skip::setValue(int value) {
    this->value = value;
}

Node_Skip *Node_Skip::getForward(int level) const {
    return forward[level];
}

void Node_Skip::setForward(int level, Node_Skip *node) {
    forward[level] = node;
}

#include "Node_Linked.h"

Node_Linked::Node_Linked(std::string key_, int value_, Node_Linked *next_) : key(key_), value(value_), next(next_){}

std::string Node_Linked::getKey() {
    return this->key;
}

int Node_Linked::getValue() {
    return this->value;
}

Node_Linked *Node_Linked::getNext() {
    return this->next;
}

void Node_Linked::setKey(std::string key_) {
    this->key = key_;
}

void Node_Linked::setValue(int value_) {
    this->value = value_;
}

void Node_Linked::setNext(Node_Linked *next_) {
    this->next = next_;
}
#include "Node.h"

Node::Node(int key_, Node *prev_, Node *next_) {
    this->key = key_;
    this->prev = prev_;
    this->next = next_;
}

int Node::getKey() {
    return this->key;
}

Node *Node::getPrev() {
    return this->prev;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setKey(int key_) {
    this->key = key_;
}

void Node::setPrev(Node *prev_) {
    this->prev = prev_;
}

void Node::setNext(Node *next_) {
    this->next = next_;
}

//Node *Node::getPrevDelete(int k) {
//    Node *prevDelete = this;
//    for (int i=1; i<k-1; i++)
//        prevDelete = prevDelete->getNext();
//    return prevDelete;
//}

Node *Node::getNextDeleted(int k) {
    Node *toDelete = this;
    for (int i=1; i<k; i++)
        toDelete = toDelete->getNext();
    return toDelete;
}
#include "CircularList.h"
#include <iostream>

CircularList::CircularList(Node *head_) {
    this->head = head_;
    if (head != nullptr)
        size = 1;
}

CircularList::~CircularList() {
    delete head;
}

Node* CircularList::getHead() {
    return this->head;
}

void CircularList::setHead(Node *head_) {
    this->head = head_;
}

int CircularList::getSize() {
//    Node* aux = this->head;
//    int n = 1;
//    while (aux->getNext() != head) {
//        aux = aux->getNext();
//        n++;
//    }
//    return n;
    return this->size;
}
/// pentru o anumita pozitie data
/*void CircularList::addNode(Node *node, int poz) {
    Node* aux = this->head;
    for (;poz--;)
        aux = aux->getNext();

    int n = getSize();
    if (poz == n)
        aux->setNext(node);
    else {
        Node *nextNode = aux->getNext();
        aux->setNext(node);
        node->setNext(nextNode);
    }
}

void CircularList::removeNode(Node *node, int poz) {
    Node* aux = this->head;
    for (;poz--;)
        aux = aux->getNext();

    if (!poz) {
        Node *nextNode = aux->getNext();
        nextNode->setPrev(nullptr);
        delete this->head;
        setHead(nextNode);
    }
    else {
        Node *prevNode = aux->getPrev();
        Node *nextNode = aux->getNext();
        prevNode->setNext(nextNode);
        delete aux;
    }
}*/

void CircularList::insertNode(int val) {
    Node *newNode = new Node(val);
    size++;
    if (head == nullptr) {
        head = newNode;
        head->setPrev(head);
        head->setNext(head);
    }
    else {
        Node *last = head->getPrev();
        last->setNext(newNode);
        newNode->setPrev(last);
        newNode->setNext(head);
        head->setPrev(newNode);
    }
}

void CircularList::deleteNode(Node *node) {
    if (head == node) {
        if (size == 1) {
            head = nullptr;
            size = 0;
        }
        else {
            head->getPrev()->setNext(head->getNext());
            head->getNext()->setPrev(head->getPrev());
            head = head->getNext();
            delete node;
            size--;
        }
    }
    else
        if (node->getNext() == head) {
            node->getPrev()->setNext(head);
            head->setPrev(node->getPrev());
            delete node;
            size--;
        }
        else {
            node->getPrev()->setNext(node->getNext());
            node->getNext()->setPrev(node->getPrev());
            delete node;
            size--;
        }
}

void CircularList::printList() {
    if (head == nullptr)
        return;
    Node *aux = head;
    do {
        std::cout << aux->getKey() << " ";
        aux = aux->getNext();
    } while (aux->getNext() != head);
    std::cout << aux->getKey() << "\n";
}
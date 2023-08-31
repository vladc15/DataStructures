#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::insert(const std::string &key, int value) {
    Node_Linked* new_node = new Node_Linked(key, value);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        /// insert at the end
        tail->setNext(new_node);
        tail = new_node;

    }
}

void LinkedList::remove(const std::string &key) {
    if (head == nullptr) {
        return;
    }
    if (head->getKey() == key) {
        Node_Linked* temp = head;
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    Node_Linked* current = head;
    Node_Linked* previous = nullptr;
    while (current != nullptr) {
        if (current->getKey() == key) {
            previous->setNext(current->getNext());
            if (current->getNext() == nullptr) {
                tail = previous;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->getNext();
    }
}

int LinkedList::search(const std::string &key) {
    Node_Linked* current = head;
    while (current != nullptr) {
        if (current->getKey() == key)
            return current->getValue();
        current = current->getNext();
    }
    return -1;
}

void LinkedList::print() {
    Node_Linked* current = head;
    while (current != nullptr) {
        std::cout << "Key: " << current->getKey() << " Value: " << current->getValue() << "\n";
        current = current->getNext();
    }
}

void LinkedList::sort() {
    if (head == nullptr || head->getNext() == nullptr) {
        return;
    }

    Node_Linked* current = head;
    Node_Linked* index = nullptr;
    std::string tempKey;
    int tempValue;

    while (current != nullptr) {
        index = current->getNext();

        while (index != nullptr) {
            if (current->getKey() > index->getKey()) {
                tempKey = current->getKey();
                tempValue = current->getValue();
                current->setKey(index->getKey());
                current->setValue(index->getValue());
                index->setKey(tempKey);
                index->setValue(tempValue);
            }

            index = index->getNext();
        }

        current = current->getNext();
    }
}

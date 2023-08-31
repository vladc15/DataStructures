#pragma once

class Node {
    int key;
    Node *prev;
    Node *next;
public:
    Node(int key_ = 0, Node *prev_ = nullptr, Node *next_ = nullptr);

    int getKey();
    Node* getPrev();
    Node* getNext();

    void setKey(int key_);
    void setPrev(Node *prev_);
    void setNext(Node *next_);

    //Node* getPrevDelete(int k);
    Node* getNextDeleted(int k);

};
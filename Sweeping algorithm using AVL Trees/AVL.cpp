#include "AVL.h"
#include "Event.h"

template class AVL<Event>;

template<typename Key>
AVL<Key>::Node::Node(const Key &k) : key(k), left(nullptr), right(nullptr), height(1) {}

template<typename Key>
Key AVL<Key>::Node::getKey() const { return key; }

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::Node::getLeft() const { return left; }

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::Node::getRight() const { return right; }

template<typename Key>
int AVL<Key>::Node::getHeight() const { return height; }

template<typename Key>
void AVL<Key>::Node::setKey(const Key &k) { this->key = k; }

template<typename Key>
void AVL<Key>::Node::setLeft(AVL::Node *l) { this->left = l; }

template<typename Key>
void AVL<Key>::Node::setRight(AVL::Node *r) { this->right = r; }

template<typename Key>
void AVL<Key>::Node::setHeight(int h) { this->height = h; }

template<typename Key>
int AVL<Key>::getHeight(AVL::Node *node) {
    if (node == nullptr)
        return 0;
    return node->getHeight();
}

template<typename Key>
int AVL<Key>::getBalanceFactor(AVL::Node *node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->getLeft()) - getHeight(node->getRight());
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::rightRotate(AVL::Node *y) {
    Node* x = y->getLeft();
    Node* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(std::max(getHeight(y->getLeft()), getHeight(y->getRight())) + 1);
    x->setHeight(std::max(getHeight(x->getLeft()), getHeight(x->getRight())) + 1);

    return x;
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::leftRotate(AVL::Node *x) {
    Node* y = x->getRight();
    Node* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(std::max(getHeight(x->getLeft()), getHeight(x->getRight())) + 1);
    y->setHeight(std::max(getHeight(y->getLeft()), getHeight(y->getRight())) + 1);

    return y;
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::insertNode(AVL::Node *node, const Key &key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->getKey())
        node->setLeft(insertNode(node->getLeft(), key));
    else if (node->getKey() < key)
        node->setRight(insertNode(node->getRight(), key));
    else
        return node;

    node->setHeight(1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight())));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->getLeft()->getKey())
        return rightRotate(node);

    if (balance < -1 && node->getRight()->getKey() < key)
        return leftRotate(node);

    if (balance > 1 && node->getLeft()->getKey() < key) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    if (balance < -1 && key < node->getRight()->getKey()) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::findNode(AVL::Node *node, const Key &key) {
    if (node == nullptr || node->getKey() == key)
        return node;

    if (key < node->getKey())
        return findNode(node->getLeft(), key);

    return findNode(node->getRight(), key);
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::findMinNode(AVL::Node *node) {
    if (node == nullptr)
        return nullptr;

    Node* current = node;
    while (current->getLeft() != nullptr)
        current = current->getLeft();

    return current;
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::eraseNode(AVL::Node *node, const Key &key) {
    if (node == nullptr)
        return node;

    if (key < node->getKey())
        node->setLeft(eraseNode(node->getLeft(), key));
    else if (node->getKey() < key)
        node->setRight(eraseNode(node->getRight(), key));
    else {
        if (node->getLeft() == nullptr || node->getRight() == nullptr) {
            Node* temp = node->getLeft() ? node->getLeft() : node->getRight();

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = findMinNode(node->getRight());
            node->setKey(temp->getKey());
            node->setRight(eraseNode(node->getRight(), temp->getKey()));
        }
    }

    if (node == nullptr)
        return node;

    node->setHeight(1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight())));

    int balance = getBalanceFactor(node);

    if (balance > 1 && getBalanceFactor(node->getLeft()) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalanceFactor(node->getLeft()) < 0) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    if (balance < -1 && getBalanceFactor(node->getRight()) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalanceFactor(node->getRight()) > 0) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}


template<typename Key>
typename AVL<Key>::Node *AVL<Key>::getMinimumNode(AVL::Node *node) {
    if (node == nullptr)
        return nullptr;

    while (node->getLeft() != nullptr)
        node = node->getLeft();

    return node;
}


template<typename Key>
AVL<Key>::AVL() : root(nullptr) {}


template<typename Key>
typename AVL<Key>::Node *AVL<Key>::getMaximumNode() {
    Node* node = root;
    if (node == nullptr) {
        return nullptr;
    }

    while (node->getRight() != nullptr)
        node = node->getRight();

    return node;
}

template<typename Key>
void AVL<Key>::insert(const Key &key) {
    root = insertNode(root, key);
}

template<typename Key>
void AVL<Key>::erase(const Key &key) {
    root = eraseNode(root, key);
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::find(const Key &key) {
    return findNode(root, key);
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::lower_bound(const Key &key) {
    Node* current = root;
    Node* result = nullptr;
    while (current != nullptr) {
        if (current->getKey() == key) {
            result = current;
            break;
        } else if (current->getKey() < key) {
            current = current->getRight();
        } else {
            result = current;
            current = current->getLeft();
        }
    }
    return result;
}

template<typename Key>
typename AVL<Key>::Node *AVL<Key>::begin() {
    return getMinimumNode(root);
}


template<typename Key>
typename AVL<Key>::Node *AVL<Key>::getPreviousNode(const Key &key) {
    //Node* node = root;
    Node *current = root;
    Node *prevNode = nullptr;

    while (current != nullptr) {
        if (current->getKey() == key) {
            if (current->getLeft() != nullptr) {
                prevNode = current->getLeft();
                while (prevNode->getRight() != nullptr)
                    prevNode = prevNode->getRight();
            }
            break;
        } else if (current->getKey() < key) {
            prevNode = current;
            current = current->getRight();
        } else {
            current = current->getLeft();
        }
    }

    return prevNode;
}


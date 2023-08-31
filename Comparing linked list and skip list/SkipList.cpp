#include "SkipList.h"

int SkipList::getRandomLevel() {
    int level_ = 1;
    while (rand() < RAND_MAX / 2 && level_ < MAX_LEVEL)
        level_++;
    return level_;
}

SkipList::SkipList() {
    level = 0;
    header = new Node_Skip(MAX_LEVEL, "", -1);
}

SkipList::~SkipList() {
    Node_Skip* current = header->getForward(0);
    while (current != nullptr) {
        Node_Skip* next = current->getForward(0);
        delete current;
        current = next;
    }
    delete header;
}

void SkipList::insert(std::string key, int value) {
    Node_Skip* current = header;
    Node_Skip* update[MAX_LEVEL + 1];

    memset(update, 0, sizeof(Node_Skip*) * (MAX_LEVEL + 1));

    for (int i = level; i >= 0; i--) {
        while (current->getForward(i) != nullptr && current->getForward(i)->getKey() < key)
            current = current->getForward(i);
        update[i] = current;
    }

    current = current->getForward(0);

    // If the key already exists, update its value
    if (current != nullptr && current->getKey() == key)
        current->setValue(value);
    else {
        // Generate a random level for the new node
        int newLevel = getRandomLevel();

        // If the new level is greater than the current level,
        // update the update array and adjust the header
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++)
                update[i] = header;
            level = newLevel;
        }

        Node_Skip* newNode = new Node_Skip(newLevel, key, value);

        // Update the forward pointers
        for (int i = 0; i <= newLevel; i++) {
            newNode->setForward(i, update[i]->getForward(i));
            update[i]->setForward(i, newNode);
        }
    }
}

int SkipList::search(std::string key) {
    Node_Skip* current = header;

    for (int i = level; i >= 0; i--)
        while (current->getForward(i) != nullptr && current->getForward(i)->getKey() < key)
            current = current->getForward(i);

    current = current->getForward(0);

    if (current != nullptr && current->getKey() == key)
        return current->getValue();

    return -1;
}

void SkipList::remove(std::string key) {
    Node_Skip* current = header;
    Node_Skip* update[MAX_LEVEL + 1];

    memset(update, 0, sizeof(Node_Skip*) * (MAX_LEVEL + 1));

    for (int i = level; i >= 0; i--) {
        while (current->getForward(i) != nullptr && current->getForward(i)->getKey() < key)
            current = current->getForward(i);
        update[i] = current;
    }

    current = current->getForward(0);

    if (current != nullptr && current->getKey() == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->getForward(i) != current)
                break;
            update[i]->setForward(i, current->getForward(i));
        }

        delete current;

        while (level > 0 && header->getForward(level) == nullptr)
            level--;
    }
}

void SkipList::print() {
    for (int i = level; i >= 0; i--) {
        Node_Skip* current = header->getForward(i);
        std::cout << "Level " << i << ": ";
        while (current != nullptr) {
            std::cout << current->getKey() << " " << current->getValue() << " ; ";
            current = current->getForward(i);
        }
        std::cout << "\n";
    }
}
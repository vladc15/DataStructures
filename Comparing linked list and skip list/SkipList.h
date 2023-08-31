#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Node_Skip.h"

const int MAX_LEVEL = 16;

class SkipList {
private:
    int level;
    Node_Skip* header;

    int getRandomLevel();

public:
    SkipList();

    ~SkipList();

    void insert(std::string key, int value);

    int search(std::string key);

    void remove(std::string key);

    void print();
};
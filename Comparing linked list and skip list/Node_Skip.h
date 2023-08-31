#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>

class Node_Skip {
private:
    std::string key;
    int value;
    Node_Skip** forward;

public:
    Node_Skip(int level, std::string key, int value);

    ~Node_Skip();

    std::string getKey() const;

    int getValue() const;

    void setValue(int value);

    Node_Skip* getForward(int level) const;

    void setForward(int level, Node_Skip* node);
};
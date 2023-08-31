#include "Event.h"

Event::Event(double x_, double y_, int index_, int type_) : x(x_), y(y_), index(index_), type(type_) {}

double Event::getX() const { return x; }

double Event::getY() const { return y; }

int Event::getIndex() const { return index; }

int Event::getType() const { return type; }

void Event::setX(double x_) { this->x = x_; }

void Event::setY(double y_) { this->y = y_; }

void Event::setIndex(int index_) { this->index = index_; }

void Event::setType(int type_) { this->type = type_; }

bool Event::operator<(const Event &e) const {
    if (this->x == e.x) {
        if (this->type == e.type) {
            return this->y < e.y;
        }
        else
            return this->type < e.type;
    }
    return this->x < e.x;
}

bool Event::operator==(const Event &e) const {
    return this->x == e.x && this->y == e.y && this->index == e.index && this->type == e.type;
}

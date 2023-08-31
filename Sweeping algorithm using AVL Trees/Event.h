#pragma once

class Event {
    double x, y;
    int index;
    int type; /// 0 - inceput, 1 - sfarsit

public:
    Event(double x_ = 0, double y_ = 0, int index_ = 0, int type_ = 0);

    double getX() const;
    double getY() const;
    int getIndex() const;
    int getType() const;

    void setX(double x_);
    void setY(double y_);
    void setIndex(int index_);
    void setType(int type_);

    bool operator<(const Event& e) const;

    bool operator==(const Event& e) const;
};

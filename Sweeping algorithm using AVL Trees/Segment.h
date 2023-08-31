#pragma once

#include <iostream>

class Segment {
    int x1, y1, x2, y2;
    int index;
public:
    Segment(int x1_ = 0, int y1_ = 0, int x2_ = 0, int y2_ = 0);

    int getX1() const;
    int getY1() const;
    int getX2() const;
    int getY2() const;
    int getIndex() const;

    void setX1(int x1_);
    void setY1(int y1_);
    void setX2(int x2_);
    void setY2(int y2_);
    void setIndex(int index_);

    bool operator<(const Segment& s) const;
};

int det(int x1, int y1, int x2, int y2, int x3, int y3);

bool pointOnSegment(int x1, int y1, int x2, int y2, int x3, int y3);

bool Intersects(const Segment& s1, const Segment& s2);

std::pair<double, double> getIntersection(const Segment& s1, const Segment& s2);
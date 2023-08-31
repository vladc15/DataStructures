#include "Segment.h"

Segment::Segment(int x1_, int y1_, int x2_, int y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}

int Segment::getX1() const { return x1; }

int Segment::getY1() const { return y1; }

int Segment::getX2() const { return x2; }

int Segment::getY2() const { return y2; }

int Segment::getIndex() const { return index; }

void Segment::setX1(int x1_) { this->x1 = x1_; }

void Segment::setY1(int y1_) { this->y1 = y1_; }

void Segment::setX2(int x2_) { this->x2 = x2_; }

void Segment::setY2(int y2_) { this->y2 = y2_; }

void Segment::setIndex(int index_) { this->index = index_; }

bool Segment::operator<(const Segment &s) const {
    if (this->x1 == s.x1) {
        if (this->y1 == s.y1) {
            if (this->x2 == s.x2) {
                return this->y2 < s.y2;
            }
            else
                return this->x2 < s.x2;
        }
        else
            return this->y1 < s.y1;
    }
    else
        return this->x1 < s.x1;
}

int det(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

bool pointOnSegment(int x1, int y1, int x2, int y2, int x3, int y3) {
    int d = det(x1, y1, x2, y2, x3, y3);
    if (d != 0)
        return false;
    if (x3 == x1 && y3 == y1)
        return true;
    if (x3 == x2 && y3 == y2)
        return true;
    if (((x3 - x1) * (x3 - x2)) < 0 || ((y3 - y1) * (y3 - y2)) < 0)
        return true;
    return false;
}

bool Intersects(const Segment &s1, const Segment &s2) {
    if (pointOnSegment(s1.getX1(), s1.getY1(), s1.getX2(), s1.getY2(), s2.getX1(), s2.getY1()))
        return true;
    if (pointOnSegment(s1.getX1(), s1.getY1(), s1.getX2(), s1.getY2(), s2.getX2(), s2.getY2()))
        return true;
    if (pointOnSegment(s2.getX1(), s2.getY1(), s2.getX2(), s2.getY2(), s1.getX1(), s1.getY1()))
        return true;
    if (pointOnSegment(s2.getX1(), s2.getY1(), s2.getX2(), s2.getY2(), s1.getX2(), s1.getY2()))
        return true;

    int d1 = det(s1.getX1(), s1.getY1(), s1.getX2(), s1.getY2(), s2.getX1(), s2.getY1());
    int d2 = det(s1.getX1(), s1.getY1(), s1.getX2(), s1.getY2(), s2.getX2(), s2.getY2());
    int d3 = det(s2.getX1(), s2.getY1(), s2.getX2(), s2.getY2(), s1.getX1(), s1.getY1());
    int d4 = det(s2.getX1(), s2.getY1(), s2.getX2(), s2.getY2(), s1.getX2(), s1.getY2());

    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;
    return false;

}

std::pair<double, double> getIntersection(const Segment &s1, const Segment &s2) {
    double a1 = s1.getY2() - s1.getY1();
    double b1 = s1.getX1() - s1.getX2();
    double c1 = a1 * s1.getX1() + b1 * s1.getY1();

    double a2 = s2.getY2() - s2.getY1();
    double b2 = s2.getX1() - s2.getX2();
    double c2 = a2 * s2.getX1() + b2 * s2.getY1();

    double det = a1 * b2 - a2 * b1;
    if (det == 0) {
        return std::make_pair(0, 0);
    } else {
        double x = (b2 * c1 - b1 * c2) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        return std::make_pair(x, y);
    }
}

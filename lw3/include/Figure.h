#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);

class Figure {
public:
    virtual ~Figure() = default;
    virtual Point center() const = 0;
    virtual operator double() const = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual std::istream& input(std::istream& is) = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

#endif // FIGURE_H

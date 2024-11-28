#include "Figure.h"

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    return figure.print(os);
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    return figure.input(is);
}
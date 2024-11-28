#ifndef POINT_H
#define POINT_H

#include <concepts>
#include <iostream>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

private:
    T x, y;
};

#endif // POINT_H
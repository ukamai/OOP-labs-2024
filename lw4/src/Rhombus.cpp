#include "Rhombus.h"
#include <cmath>

template <typename T>
requires Scalar<T>
Rhombus<T>::Rhombus(const std::vector<Point<T>>& points) {
    for (const auto& p : points) {
        this->points.push_back(std::make_unique<Point<T>>(p));
    }
}

template <typename T>
requires Scalar<T>
Point<T> Rhombus<T>::center() const {
    T centerX = 0, centerY = 0;
    for (const auto& p : points) {
        centerX += p->getX();
        centerY += p->getY();
    }
    return Point<T>(centerX / points.size(), centerY / points.size());
}

template <typename T>
requires Scalar<T>
Rhombus<T>::operator double() const {
    T d1 = std::sqrt(std::pow(points[0]->getX() - points[2]->getX(), 2) + std::pow(points[0]->getY() - points[2]->getY(), 2));
    T d2 = std::sqrt(std::pow(points[1]->getX() - points[3]->getX(), 2) + std::pow(points[1]->getY() - points[3]->getY(), 2));
    return 0.5 * d1 * d2;
}

template <typename T>
requires Scalar<T>
std::ostream& Rhombus<T>::print(std::ostream& os) const {
    for (const auto& p : points) {
        os << *p << " ";
    }
    return os;
}

template <typename T>
requires Scalar<T>
std::istream& Rhombus<T>::input(std::istream& is) {
    points.clear();
    points.resize(4);
    for (auto& p : points) {
        T x, y;
        is >> x >> y;
        p = std::make_unique<Point<T>>(x, y);
    }
    return is;
}

// Explicit instantiation for int
template class Rhombus<int>;
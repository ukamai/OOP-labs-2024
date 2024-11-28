#include "Pentagon.h"
#include <cmath>

template <typename T>
requires Scalar<T>
Pentagon<T>::Pentagon(const std::vector<Point<T>>& points) {
    for (const auto& p : points) {
        this->points.push_back(std::make_unique<Point<T>>(p));
    }
}

template <typename T>
requires Scalar<T>
Point<T> Pentagon<T>::center() const {
    T centerX = 0, centerY = 0;
    for (const auto& p : points) {
        centerX += p->getX();
        centerY += p->getY();
    }
    return Point<T>(centerX / points.size(), centerY / points.size());
}

template <typename T>
requires Scalar<T>
Pentagon<T>::operator double() const {
    T area = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        size_t j = (i + 1) % points.size();
        area += points[i]->getX() * points[j]->getY() - points[j]->getX() * points[i]->getY();
    }
    return std::abs(area) / 2.0;
}

template <typename T>
requires Scalar<T>
std::ostream& Pentagon<T>::print(std::ostream& os) const {
    for (const auto& p : points) {
        os << *p << " ";
    }
    return os;
}

template <typename T>
requires Scalar<T>
std::istream& Pentagon<T>::input(std::istream& is) {
    points.clear();
    points.resize(5);
    for (auto& p : points) {
        T x, y;
        is >> x >> y;
        p = std::make_unique<Point<T>>(x, y);
    }
    return is;
}

// Explicit instantiation for int
template class Pentagon<int>;
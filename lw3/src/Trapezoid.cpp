#include "Trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid(const std::vector<Point>& points) : points(points) {}

Point Trapezoid::center() const {
    double centerX = 0, centerY = 0;
    for (const auto& p : points) {
        centerX += p.x;
        centerY += p.y;
    }
    return Point(centerX / points.size(), centerY / points.size());
}

Trapezoid::operator double() const {
    double base1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double base2 = std::sqrt(std::pow(points[3].x - points[2].x, 2) + std::pow(points[3].y - points[2].y, 2));
    double height = std::abs(points[0].y - points[2].y);
    return 0.5 * (base1 + base2) * height;
}

std::ostream& Trapezoid::print(std::ostream& os) const {
    for (const auto& p : points) {
        os << p << " ";
    }
    return os;
}

std::istream& Trapezoid::input(std::istream& is) {
    points.resize(4);
    for (auto& p : points) {
        is >> p;
    }
    return is;
}

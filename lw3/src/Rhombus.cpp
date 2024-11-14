#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus(const std::vector<Point>& points) : points(points) {}

Point Rhombus::center() const {
    double centerX = 0, centerY = 0;
    for (const auto& p : points) {
        centerX += p.x;
        centerY += p.y;
    }
    return Point(centerX / points.size(), centerY / points.size());
}

Rhombus::operator double() const {
    double d1 = std::sqrt(std::pow(points[0].x - points[2].x, 2) + std::pow(points[0].y - points[2].y, 2));
    double d2 = std::sqrt(std::pow(points[1].x - points[3].x, 2) + std::pow(points[1].y - points[3].y, 2));
    return 0.5 * d1 * d2;
}

std::ostream& Rhombus::print(std::ostream& os) const {
    for (const auto& p : points) {
        os << p << " ";
    }
    return os;
}

std::istream& Rhombus::input(std::istream& is) {
    points.resize(4);
    for (auto& p : points) {
        is >> p;
    }
    return is;
}

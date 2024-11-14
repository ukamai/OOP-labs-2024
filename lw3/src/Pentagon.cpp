#include "Pentagon.h"
#include <cmath>

Pentagon::Pentagon(const std::vector<Point>& points) : points(points) {}

Point Pentagon::center() const {
    double centerX = 0, centerY = 0;
    for (const auto& p : points) {
        centerX += p.x;
        centerY += p.y;
    }
    return Point(centerX / points.size(), centerY / points.size());
}

Pentagon::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        size_t j = (i + 1) % points.size();
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    return std::abs(area) / 2.0;
}

std::ostream& Pentagon::print(std::ostream& os) const {
    for (const auto& p : points) {
        os << p << " ";
    }
    return os;
}

std::istream& Pentagon::input(std::istream& is) {
    points.resize(5);
    for (auto& p : points) {
        is >> p;
    }
    return is;
}

#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(const std::vector<Point>& points);

    Point center() const override;
    operator double() const override;
    std::ostream& print(std::ostream& os) const override;
    std::istream& input(std::istream& is) override;

private:
    std::vector<Point> points;
};

#endif // TRAPEZOID_H

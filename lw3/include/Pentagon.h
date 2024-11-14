#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure {
public:
    Pentagon() = default;
    Pentagon(const std::vector<Point>& points);

    Point center() const override;
    operator double() const override;
    std::ostream& print(std::ostream& os) const override;
    std::istream& input(std::istream& is) override;

private:
    std::vector<Point> points;
};

#endif // PENTAGON_H

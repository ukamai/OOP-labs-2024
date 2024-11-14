#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus() = default;
    Rhombus(const std::vector<Point>& points);

    Point center() const override;
    operator double() const override;
    std::ostream& print(std::ostream& os) const override;
    std::istream& input(std::istream& is) override;

private:
    std::vector<Point> points;
};

#endif // RHOMBUS_H

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <vector>
#include <memory>

template <typename T>
requires Scalar<T>
class Rhombus : public Figure<T> {
public:
    Rhombus() = default;
    Rhombus(const std::vector<Point<T>>& points);

    Point<T> center() const override;
    operator double() const override;
    std::ostream& print(std::ostream& os) const override;
    std::istream& input(std::istream& is) override;

private:
    std::vector<std::unique_ptr<Point<T>>> points;
};

#endif // RHOMBUS_H
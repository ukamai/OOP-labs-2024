#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <vector>
#include <memory>

template <typename T>
requires Scalar<T>
class Pentagon : public Figure<T> {
public:
    Pentagon() = default;
    Pentagon(const std::vector<Point<T>>& points);

    Point<T> center() const override;
    operator double() const override;
    std::ostream& print(std::ostream& os) const override;
    std::istream& input(std::istream& is) override;

private:
    std::vector<std::unique_ptr<Point<T>>> points;
};

#endif // PENTAGON_H
#ifndef FIGURE_H
#define FIGURE_H

#include <concepts>
#include <iostream>
#include "Point.h"

template <typename T>
requires Scalar<T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual Point<T> center() const = 0;
    virtual operator double() const = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual std::istream& input(std::istream& is) = 0;
};

template <typename T>
requires Scalar<T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    return figure.print(os);
}

template <typename T>
requires Scalar<T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    return figure.input(is);
}

#endif // FIGURE_H
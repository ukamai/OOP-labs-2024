#include <iostream>
#include "include/Twelve.h"

int main() {
    Twelve a("1A2B");
    Twelve b("345");

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    Twelve c = a + b;
    std::cout << "a + b = " << c << std::endl;

    Twelve d = a - b;
    std::cout << "a - b = " << d << std::endl;

    if (a == b) {
        std::cout << "a == b" << std::endl;
    } else {
        std::cout << "a != b" << std::endl;
    }

    if (a > b) {
        std::cout << "a > b" << std::endl;
    } else {
        std::cout << "a <= b" << std::endl;
    }

    return 0;
}

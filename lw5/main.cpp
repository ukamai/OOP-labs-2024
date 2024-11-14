#include <iostream>
#include <memory_resource>
#include "CustomMemoryResource.h"
#include "CustomList.h"

struct ComplexType {
    int a;
    double b;
    std::string c;

    ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
};

int main() {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    CustomList<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    for (auto it = intList.begin(); it != intList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::pmr::polymorphic_allocator<ComplexType> complexAlloc(&memRes);
    CustomList<ComplexType> complexList(complexAlloc);
    complexList.push_back(ComplexType(1, 1.1, "one"));
    complexList.push_back(ComplexType(2, 2.2, "two"));
    complexList.push_back(ComplexType(3, 3.3, "three"));

    for (auto it = complexList.begin(); it != complexList.end(); ++it) {
        std::cout << it->a << " " << it->b << " " << it->c << std::endl;
    }

    return 0;
}

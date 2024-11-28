#include <iostream>
#include "Array.h"
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    while (true) {
        std::cout << "1. Add Trapezoid\n"
                  << "2. Add Rhombus\n"
                  << "3. Add Pentagon\n"
                  << "4. Print all figures\n"
                  << "5. Calculate total area\n"
                  << "6. Delete figure by index\n"
                  << "7. Exit\n"
                  << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            auto trapezoid = std::make_shared<Trapezoid<int>>();
            std::cout << "Enter coordinates for Trapezoid (4 points): ";
            std::cin >> *trapezoid;
            figures.push_back(trapezoid);
        } else if (choice == 2) {
            auto rhombus = std::make_shared<Rhombus<int>>();
            std::cout << "Enter coordinates for Rhombus (4 points): ";
            std::cin >> *rhombus;
            figures.push_back(rhombus);
        } else if (choice == 3) {
            auto pentagon = std::make_shared<Pentagon<int>>();
            std::cout << "Enter coordinates for Pentagon (5 points): ";
            std::cin >> *pentagon;
            figures.push_back(pentagon);
        } else if (choice == 4) {
            for (size_t i = 0; i < figures.size(); ++i) {
                std::cout << "Figure " << i << ":\n";
                std::cout << "Center: " << figures[i]->center() << "\n";
                std::cout << "Area: " << static_cast<double>(*figures[i]) << "\n";
                std::cout << *figures[i] << "\n";
            }
        } else if (choice == 5) {
            double totalArea = 0.0;
            for (size_t i = 0; i < figures.size(); ++i) {
                totalArea += static_cast<double>(*figures[i]);
            }
            std::cout << "Total area: " << totalArea << "\n";
        } else if (choice == 6) {
            size_t index;
            std::cout << "Enter index to delete: ";
            std::cin >> index;
            if (index < figures.size()) {
                figures.erase(index);
            } else {
                std::cout << "Invalid index\n";
            }
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}

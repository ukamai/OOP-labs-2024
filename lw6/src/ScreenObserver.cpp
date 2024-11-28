#include "ScreenObserver.h"
#include <iostream>

void ScreenObserver::update(const std::string& event) {
    std::cout << event << std::endl;
}
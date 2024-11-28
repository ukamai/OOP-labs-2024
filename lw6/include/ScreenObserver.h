#ifndef SCREENOBSERVER_H
#define SCREENOBSERVER_H

#include "Observer.h"

class ScreenObserver : public Observer {
public:
    void update(const std::string& event) override;
};

#endif // SCREENOBSERVER_H
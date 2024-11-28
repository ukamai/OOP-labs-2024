#include "NPC.h"
#include "BattleVisitor.h"
#include "Observer.h"
#include <iostream>

NPC::NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; }

Orc::Orc(const std::string& name, int x, int y) : NPC(name, x, y) {}
void Orc::accept(BattleVisitor& visitor) { /* Не нужно вызывать visit здесь */ }
void Orc::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

Knight::Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}
void Knight::accept(BattleVisitor& visitor) { /* Не нужно вызывать visit здесь */ }
void Knight::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

Bear::Bear(const std::string& name, int x, int y) : NPC(name, x, y) {}
void Bear::accept(BattleVisitor& visitor) { /* Не нужно вызывать visit здесь */ }
void Bear::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}
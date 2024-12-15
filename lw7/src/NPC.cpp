#include "NPC.h"
#include "Observer.h"
#include <cmath>

void NPC::move(int dx, int dy) {
    x += dx;
    y += dy;
}

bool NPC::canKill(const NPC& other) const {
    return std::abs(x - other.x) <= killDistance && std::abs(y - other.y) <= killDistance;
}

void Orc::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Squirrel::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Druid::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Knight::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Elf::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Dragon::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Bear::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Rogue::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Werewolf::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Princess::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Frog::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void SlaveTrader::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Pegasus::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Bittern::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Desman::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}

void Bull::notifyObservers(const std::string& event) {
    for (auto obs : observers) {
        obs->update(event);
    }
}
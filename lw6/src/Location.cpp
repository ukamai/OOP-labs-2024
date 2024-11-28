#include "Location.h"
#include "NPCFactory.h"
#include "BattleVisitor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void Location::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

void Location::removeNPC(NPC* npc) {
    npcs.erase(std::remove(npcs.begin(), npcs.end(), npc), npcs.end());
    delete npc;
}

void Location::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& npc : npcs) {
        file << npc->getName() << " " << npc->getX() << " " << npc->getY() << std::endl;
    }
}

void Location::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string name;
    int x, y;
    while (file >> name >> x >> y) {
        addNPC(NPCFactory::createNPC(name, name, x, y));
    }
}

void Location::printNPCs() const {
    for (const auto& npc : npcs) {
        std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
}

void Location::startBattle(int range) {
    BattleVisitor visitor;
    for (auto it1 = npcs.begin(); it1 != npcs.end(); ++it1) {
        for (auto it2 = it1 + 1; it2 != npcs.end(); ++it2) {
            if (std::abs((*it1)->getX() - (*it2)->getX()) <= range && std::abs((*it1)->getY() - (*it2)->getY()) <= range) {
                if (dynamic_cast<Orc*>(*it1) && dynamic_cast<Knight*>(*it2)) {
                    visitor.visit(*dynamic_cast<Orc*>(*it1), *dynamic_cast<Knight*>(*it2));
                } else if (dynamic_cast<Orc*>(*it1) && dynamic_cast<Bear*>(*it2)) {
                    visitor.visit(*dynamic_cast<Orc*>(*it1), *dynamic_cast<Bear*>(*it2));
                } else if (dynamic_cast<Knight*>(*it1) && dynamic_cast<Bear*>(*it2)) {
                    visitor.visit(*dynamic_cast<Knight*>(*it1), *dynamic_cast<Bear*>(*it2));
                }
                removeNPC(*it1);
                removeNPC(*it2);
                return;
            }
        }
    }
}
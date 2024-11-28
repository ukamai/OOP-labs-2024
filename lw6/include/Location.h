#ifndef LOCATION_H
#define LOCATION_H

#include "NPC.h"
#include <vector>

class Location {
public:
    void addNPC(NPC* npc);
    void removeNPC(NPC* npc);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printNPCs() const;
    void startBattle(int range);

private:
    std::vector<NPC*> npcs;
};

#endif // LOCATION_H
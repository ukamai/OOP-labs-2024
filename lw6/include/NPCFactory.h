#ifndef NPCFACTORY_H
#define NPCFACTORY_H

#include "NPC.h"
#include <string>

class NPCFactory {
public:
    static NPC* createNPC(const std::string& type, const std::string& name, int x, int y);
};

#endif // NPCFACTORY_H
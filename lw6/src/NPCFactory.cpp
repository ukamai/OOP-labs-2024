#include "NPCFactory.h"
#include "NPC.h"

NPC* NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Orc") return new Orc(name, x, y);
    if (type == "Knight") return new Knight(name, x, y);
    if (type == "Bear") return new Bear(name, x, y);
    return nullptr;
}
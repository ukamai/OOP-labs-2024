#include "NPCFactory.h"
#include "NPC.h"

NPC* NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Orc") return new Orc(name, x, y);
    if (type == "Squirrel") return new Squirrel(name, x, y);
    if (type == "Druid") return new Druid(name, x, y);
    if (type == "Knight") return new Knight(name, x, y);
    if (type == "Elf") return new Elf(name, x, y);
    if (type == "Dragon") return new Dragon(name, x, y);
    if (type == "Bear") return new Bear(name, x, y);
    if (type == "Rogue") return new Rogue(name, x, y);
    if (type == "Werewolf") return new Werewolf(name, x, y);
    if (type == "Princess") return new Princess(name, x, y);
    if (type == "Frog") return new Frog(name, x, y);
    if (type == "SlaveTrader") return new SlaveTrader(name, x, y);
    if (type == "Pegasus") return new Pegasus(name, x, y);
    if (type == "Bittern") return new Bittern(name, x, y);
    if (type == "Desman") return new Desman(name, x, y);
    if (type == "Bull") return new Bull(name, x, y);
    return nullptr;
}
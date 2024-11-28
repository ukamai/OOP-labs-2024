#include "Location.h"
#include "NPCFactory.h"
#include "ScreenObserver.h"
#include "FileObserver.h"
#include <iostream>

int main() {
    Location location;
    ScreenObserver screenObserver;
    FileObserver fileObserver;

    location.addNPC(NPCFactory::createNPC("Orc", "Grommash", 100, 100));
    location.addNPC(NPCFactory::createNPC("Knight", "Arthas", 200, 200));
    location.addNPC(NPCFactory::createNPC("Bear", "Misha", 300, 300));

    location.printNPCs();

    location.startBattle(100);

    location.saveToFile("location.txt");

    return 0;
}
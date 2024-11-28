#include "BattleVisitor.h"
#include "NPC.h"
#include <iostream>

void BattleVisitor::visit(Orc& orc, Knight& knight) {
    orc.notifyObservers("Orc " + orc.getName() + " killed Knight " + knight.getName());
    knight.notifyObservers("Knight " + knight.getName() + " was killed by Orc " + orc.getName());
}

void BattleVisitor::visit(Orc& orc, Bear& bear) {
    orc.notifyObservers("Orc " + orc.getName() + " killed Bear " + bear.getName());
    bear.notifyObservers("Bear " + bear.getName() + " was killed by Orc " + orc.getName());
}

void BattleVisitor::visit(Knight& knight, Bear& bear) {
    knight.notifyObservers("Knight " + knight.getName() + " killed Bear " + bear.getName());
    bear.notifyObservers("Bear " + bear.getName() + " was killed by Knight " + knight.getName());
}
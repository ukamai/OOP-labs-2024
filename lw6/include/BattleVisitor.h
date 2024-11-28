#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

class Orc;
class Knight;
class Bear;

class BattleVisitor {
public:
    void visit(Orc& orc, Knight& knight);
    void visit(Orc& orc, Bear& bear);
    void visit(Knight& knight, Bear& bear);
};

#endif // BATTLEVISITOR_H
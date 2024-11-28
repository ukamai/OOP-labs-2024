#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>

class NPC {
public:
    NPC(const std::string& name, int x, int y);
    virtual ~NPC() = default;

    virtual void accept(class BattleVisitor& visitor) = 0;
    virtual void notifyObservers(const std::string& event) = 0;

    std::string getName() const;
    int getX() const;
    int getY() const;

protected:
    std::string name;
    int x, y;
    std::vector<class Observer*> observers;
};

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y);
    void accept(BattleVisitor& visitor) override;
    void notifyObservers(const std::string& event) override;
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y);
    void accept(BattleVisitor& visitor) override;
    void notifyObservers(const std::string& event) override;
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y);
    void accept(BattleVisitor& visitor) override;
    void notifyObservers(const std::string& event) override;
};

#endif // NPC_H
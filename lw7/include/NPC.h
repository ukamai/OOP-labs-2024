#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <mutex>

class Observer; // Предварительное объявление

class NPC {
public:
    NPC(const std::string& name, int x, int y, int moveDistance, int killDistance) 
        : name(name), x(x), y(y), moveDistance(moveDistance), killDistance(killDistance), alive(true) {}
    virtual ~NPC() = default;

    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getMoveDistance() const { return moveDistance; }
    int getKillDistance() const { return killDistance; }
    bool isAlive() const { return alive; }
    void setAlive(bool alive) { this->alive = alive; }

    void move(int dx, int dy);
    bool canKill(const NPC& other) const;

    virtual void notifyObservers(const std::string& event) = 0; // Добавляем чисто виртуальный метод

protected:
    std::string name;
    int x, y;
    int moveDistance;
    int killDistance;
    bool alive;
    std::vector<Observer*> observers; // Добавляем список наблюдателей
};

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y) : NPC(name, x, y, 20, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Squirrel : public NPC {
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y, 5, 5) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Druid : public NPC {
public:
    Druid(const std::string& name, int x, int y) : NPC(name, x, y, 10, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y) : NPC(name, x, y, 30, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Elf : public NPC {
public:
    Elf(const std::string& name, int x, int y) : NPC(name, x, y, 10, 50) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Dragon : public NPC {
public:
    Dragon(const std::string& name, int x, int y) : NPC(name, x, y, 50, 30) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y) : NPC(name, x, y, 5, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Rogue : public NPC {
public:
    Rogue(const std::string& name, int x, int y) : NPC(name, x, y, 10, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Werewolf : public NPC {
public:
    Werewolf(const std::string& name, int x, int y) : NPC(name, x, y, 40, 5) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Princess : public NPC {
public:
    Princess(const std::string& name, int x, int y) : NPC(name, x, y, 1, 1) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Frog : public NPC {
public:
    Frog(const std::string& name, int x, int y) : NPC(name, x, y, 1, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class SlaveTrader : public NPC {
public:
    SlaveTrader(const std::string& name, int x, int y) : NPC(name, x, y, 10, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Pegasus : public NPC {
public:
    Pegasus(const std::string& name, int x, int y) : NPC(name, x, y, 30, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Bittern : public NPC {
public:
    Bittern(const std::string& name, int x, int y) : NPC(name, x, y, 50, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Desman : public NPC {
public:
    Desman(const std::string& name, int x, int y) : NPC(name, x, y, 5, 20) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

class Bull : public NPC {
public:
    Bull(const std::string& name, int x, int y) : NPC(name, x, y, 30, 10) {}
    void notifyObservers(const std::string& event) override; // Реализация метода
};

#endif // NPC_H
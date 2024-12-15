#include "NPCFactory.h"
#include "NPC.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
#include <queue>
#include <shared_mutex>
#include <fstream> // Для работы с файлами

const int MAP_SIZE = 1000;
const int GAME_DURATION = 30; // Игра длится 30 секунд

std::vector<NPC*> npcs;
std::queue<std::pair<NPC*, NPC*>> battleQueue;
std::shared_mutex npcsMutex;
std::mutex battleQueueMutex;
std::mutex printMutex;
std::mutex logMutex; // Мьютекс для синхронизации записи в лог-файл
std::condition_variable battleCV;
bool running = true;

// Список доступных типов NPC
const std::vector<std::string> availableNPCs = {
    "Orc", "Squirrel", "Druid", "Knight", "Elf", "Dragon", "Bear", "Rogue",
    "Werewolf", "Princess", "Frog", "SlaveTrader", "Pegasus", "Bittern",
    "Desman", "Bull"
};

// Функция для получения случайного типа NPC
std::string getRandomNPCType() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, availableNPCs.size() - 1);
    return availableNPCs[dis(gen)];
}

// Функция для записи в лог-файл
void logEvent(const std::string& event) {
    std::lock_guard<std::mutex> logLock(logMutex);
    std::ofstream logFile("log.txt", std::ios::app); // Открываем файл в режиме добавления
    if (logFile.is_open()) {
        logFile << event << std::endl;
        logFile.close();
    }
}

// Функция для очистки лог-файла
void clearLogFile() {
    std::ofstream logFile("log.txt", std::ios::trunc); // Открываем файл в режиме перезаписи
    if (logFile.is_open()) {
        logFile.close();
    }
}

void moveNPCs() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1, 1);

    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::shared_lock lock(npcsMutex);
        for (auto& npc : npcs) {
            if (npc->isAlive()) {
                int dx = dis(gen) * npc->getMoveDistance();
                int dy = dis(gen) * npc->getMoveDistance();
                npc->move(dx, dy);

                // Проверка на выход за границы карты
                npc->move(std::max(0, npc->getX()) - npc->getX(), std::max(0, npc->getY()) - npc->getY());
                npc->move(std::min(MAP_SIZE - 1, npc->getX()) - npc->getX(), std::min(MAP_SIZE - 1, npc->getY()) - npc->getY());

                // Проверка на возможность убийства
                for (auto& other : npcs) {
                    if (npc != other && npc->canKill(*other)) {
                        std::unique_lock battleLock(battleQueueMutex);
                        battleQueue.push({npc, other});
                        battleCV.notify_one();
                    }
                }
            }
        }
    }
}

void processBattles() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    while (running) {
        std::unique_lock battleLock(battleQueueMutex);
        battleCV.wait(battleLock, []() { return !battleQueue.empty() || !running; });
        if (!running) break;

        auto [npc1, npc2] = battleQueue.front();
        battleQueue.pop();
        battleLock.unlock();

        if (npc1->isAlive() && npc2->isAlive()) {
            int attack1 = dis(gen);
            int defense2 = dis(gen);
            int attack2 = dis(gen);
            int defense1 = dis(gen);

            if (attack1 > defense2) {
                npc2->setAlive(false);
                logEvent(npc1->getName() + " убил " + npc2->getName()); // Логируем убийство
            }
            if (attack2 > defense1) {
                npc1->setAlive(false);
                logEvent(npc2->getName() + " убил " + npc1->getName()); // Логируем убийство
            }
        }
    }
}

void printMap() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard printLock(printMutex);
        std::cout << "Карта:" << std::endl;
        std::shared_lock lock(npcsMutex);
        for (const auto& npc : npcs) {
            if (npc->isAlive()) {
                std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
            }
        }
        std::cout << "-------------------------" << std::endl;
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, MAP_SIZE - 1);

    // Очищаем лог-файл перед началом программы
    clearLogFile();

    // Создаем 50 случайных NPC в случайных локациях
    for (int i = 0; i < 50; ++i) {
        std::string type = getRandomNPCType(); // Выбираем случайный тип NPC
        npcs.push_back(NPCFactory::createNPC(type, type + std::to_string(i), dis(gen), dis(gen)));
    }

    auto startTime = std::chrono::steady_clock::now();

    std::thread movementThread(moveNPCs);
    std::thread battleThread(processBattles);
    std::thread printThread(printMap);

    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(GAME_DURATION)) {
        // Основной цикл игры
    }

    running = false;
    battleCV.notify_all();

    movementThread.join();
    battleThread.join();
    printThread.join();

    std::cout << "Игра завершена. Выжившие NPC:" << std::endl;
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }

    return 0;
}
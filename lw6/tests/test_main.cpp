#include <gtest/gtest.h>
#include "../include/NPC.h"
#include "../include/NPCFactory.h"
#include "../include/BattleVisitor.h"
#include "../include/Observer.h"
#include "../include/ScreenObserver.h"
#include "../include/FileObserver.h"
#include "../include/Location.h"
#include <fstream>

// Тесты для класса NPC
TEST(NPCTest, Constructor) {
    Orc orc("Grommash", 100, 100);
    EXPECT_EQ(orc.getName(), "Grommash");
    EXPECT_EQ(orc.getX(), 100);
    EXPECT_EQ(orc.getY(), 100);
}

TEST(NPCTest, AcceptVisitor) {
    Orc orc("Grommash", 100, 100);
    Knight knight("Arthas", 200, 200);
    BattleVisitor visitor;
    orc.accept(visitor);
    knight.accept(visitor);
}

// Тесты для класса NPCFactory
TEST(NPCFactoryTest, CreateNPC) {
    NPC* orc = NPCFactory::createNPC("Orc", "Grommash", 100, 100);
    EXPECT_NE(orc, nullptr);
    EXPECT_EQ(orc->getName(), "Grommash");
    EXPECT_EQ(orc->getX(), 100);
    EXPECT_EQ(orc->getY(), 100);
    delete orc;

    NPC* knight = NPCFactory::createNPC("Knight", "Arthas", 200, 200);
    EXPECT_NE(knight, nullptr);
    EXPECT_EQ(knight->getName(), "Arthas");
    EXPECT_EQ(knight->getX(), 200);
    EXPECT_EQ(knight->getY(), 200);
    delete knight;

    NPC* bear = NPCFactory::createNPC("Bear", "Misha", 300, 300);
    EXPECT_NE(bear, nullptr);
    EXPECT_EQ(bear->getName(), "Misha");
    EXPECT_EQ(bear->getX(), 300);
    EXPECT_EQ(bear->getY(), 300);
    delete bear;
}

// Тесты для класса BattleVisitor
TEST(BattleVisitorTest, VisitOrcKnight) {
    Orc orc("Grommash", 100, 100);
    Knight knight("Arthas", 200, 200);
    BattleVisitor visitor;
    visitor.visit(orc, knight);
}

TEST(BattleVisitorTest, VisitOrcBear) {
    Orc orc("Grommash", 100, 100);
    Bear bear("Misha", 300, 300);
    BattleVisitor visitor;
    visitor.visit(orc, bear);
}

TEST(BattleVisitorTest, VisitKnightBear) {
    Knight knight("Arthas", 200, 200);
    Bear bear("Misha", 300, 300);
    BattleVisitor visitor;
    visitor.visit(knight, bear);
}

// Тесты для класса Observer
TEST(ObserverTest, ScreenObserverUpdate) {
    ScreenObserver screenObserver;
    testing::internal::CaptureStdout();
    screenObserver.update("Test event");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Test event\n");
}

TEST(ObserverTest, FileObserverUpdate) {
    FileObserver fileObserver;
    fileObserver.update("Test event");
    std::ifstream logFile("log.txt");
    std::string line;
    std::getline(logFile, line);
    EXPECT_EQ(line, "Test event");
    logFile.close();
}

// Тесты для класса Location
TEST(LocationTest, AddNPC) {
    Location location;
    NPC* orc = NPCFactory::createNPC("Orc", "Grommash", 100, 100);
    location.addNPC(orc);
    location.printNPCs();
}

TEST(LocationTest, RemoveNPC) {
    Location location;
    NPC* orc = NPCFactory::createNPC("Orc", "Grommash", 100, 100);
    location.addNPC(orc);
    location.removeNPC(orc);
    location.printNPCs();
}

TEST(LocationTest, SaveAndLoad) {
    Location location;
    NPC* orc = NPCFactory::createNPC("Orc", "Grommash", 100, 100);
    location.addNPC(orc);
    location.saveToFile("test_location.txt");

    Location loadedLocation;
    loadedLocation.loadFromFile("test_location.txt");
    loadedLocation.printNPCs();
}

TEST(LocationTest, StartBattle) {
    Location location;
    NPC* orc = NPCFactory::createNPC("Orc", "Grommash", 100, 100);
    NPC* knight = NPCFactory::createNPC("Knight", "Arthas", 200, 200);
    location.addNPC(orc);
    location.addNPC(knight);
    location.startBattle(100);
    location.printNPCs();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
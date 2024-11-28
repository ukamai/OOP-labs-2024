cmake_minimum_required(VERSION 3.10)
project(GeometryFigures)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Добавляем основной исполняемый файл
add_executable(GeometryFigures main.cpp src/NPC.cpp src/NPCFactory.cpp src/BattleVisitor.cpp src/Observer.cpp src/ScreenObserver.cpp src/FileObserver.cpp src/Location.cpp)

# Добавляем тесты
find_package(GTest REQUIRED)

add_executable(tests tests/test_main.cpp src/NPC.cpp src/NPCFactory.cpp src/BattleVisitor.cpp src/Observer.cpp src/ScreenObserver.cpp src/FileObserver.cpp src/Location.cpp)

target_link_libraries(tests GTest::GTest GTest::Main)
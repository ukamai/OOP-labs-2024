cmake_minimum_required(VERSION 3.10)

project(GeometryFigures)

set(CMAKE_CXX_STANDARD 17)

# Установка путей для заголовочных файлов
include_directories(${CMAKE_SOURCE_DIR}/include)

# Добавление исходных файлов для основного проекта
add_executable(GeometryFigures
    main.cpp
    src/Figure.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
)

# Добавление Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Добавление исходных файлов тестов
add_executable(GeometryFiguresTests
    tests/geometry_tests.cpp
    src/Figure.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
)

# Установка путей для заголовочных файлов тестов
target_include_directories(GeometryFiguresTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Линковка тестов с Google Test
target_link_libraries(GeometryFiguresTests gtest_main)

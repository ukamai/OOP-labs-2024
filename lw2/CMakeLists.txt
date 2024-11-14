cmake_minimum_required(VERSION 3.10)

project(TwelveProject)

set(CMAKE_CXX_STANDARD 11)

# Установка путей для заголовочных файлов
include_directories(${CMAKE_SOURCE_DIR}/include)

# Добавление исходных файлов для основного проекта
add_executable(TwelveProject
    main.cpp
    src/Twelve.cpp
)

# Добавление Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Добавление исходных файлов тестов
add_executable(TwelveProjectTests
    tests/twelve_tests.cpp
    src/Twelve.cpp
)

# Установка путей для заголовочных файлов тестов
target_include_directories(TwelveProjectTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Линковка тестов с Google Test
target_link_libraries(TwelveProjectTests gtest_main)

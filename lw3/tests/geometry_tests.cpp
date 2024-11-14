#include <gtest/gtest.h>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

// Тест для трапеции
TEST(TrapezoidTest, AreaCalculation) {
    std::vector<Point> points = {{0, 0}, {4, 0}, {3, 2}, {1, 2}};
    Trapezoid trapezoid(points);
    EXPECT_NEAR(static_cast<double>(trapezoid), 6.0, 1e-6);
}

TEST(TrapezoidTest, CenterCalculation) {
    std::vector<Point> points = {{0, 0}, {4, 0}, {3, 2}, {1, 2}};
    Trapezoid trapezoid(points);
    Point center = trapezoid.center();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

// Тест для ромба
TEST(RhombusTest, AreaCalculation) {
    std::vector<Point> points = {{0, 0}, {2, 2}, {4, 0}, {2, -2}};
    Rhombus rhombus(points);
    EXPECT_NEAR(static_cast<double>(rhombus), 8.0, 1e-6);
}

TEST(RhombusTest, CenterCalculation) {
    std::vector<Point> points = {{0, 0}, {2, 2}, {4, 0}, {2, -2}};
    Rhombus rhombus(points);
    Point center = rhombus.center();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 0.0, 1e-6);
}

// Тест для пятиугольника
TEST(PentagonTest, AreaCalculation) {
    std::vector<Point> points = {{0, 0}, {2, 0}, {3, 2}, {1, 4}, {-1, 2}};
    Pentagon pentagon(points);
    EXPECT_NEAR(static_cast<double>(pentagon), 10.0, 1e-6);
}

TEST(PentagonTest, CenterCalculation) {
    std::vector<Point> points = {{0, 0}, {2, 0}, {3, 2}, {1, 4}, {-1, 2}};
    Pentagon pentagon(points);
    Point center = pentagon.center();
    EXPECT_NEAR(center.x, 1.0, 1e-6);
    EXPECT_NEAR(center.y, 1.6, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>
#include <memory>
#include "Point.h"
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

TEST(TrapezoidTest, CenterCalculation) {
    std::vector<Point<int>> points = {
        Point<int>(0, 0),
        Point<int>(4, 0),
        Point<int>(3, 2),
        Point<int>(1, 2)
    };
    Trapezoid<int> trapezoid(points);
    Point<int> center = trapezoid.center();
    EXPECT_EQ(center.getX(), 2);
    EXPECT_EQ(center.getY(), 1);
}

TEST(TrapezoidTest, AreaCalculation) {
    std::vector<Point<int>> points = {
        Point<int>(0, 0),
        Point<int>(4, 0),
        Point<int>(3, 2),
        Point<int>(1, 2)
    };
    Trapezoid<int> trapezoid(points);
    double area = static_cast<double>(trapezoid);
    EXPECT_NEAR(area, 6.0, 1e-6);
}

TEST(RhombusTest, CenterCalculation) {
    std::vector<Point<int>> points = {
        Point<int>(1, 0),
        Point<int>(2, 2),
        Point<int>(3, 0),
        Point<int>(2, -2)
    };
    Rhombus<int> rhombus(points);
    Point<int> center = rhombus.center();
    EXPECT_EQ(center.getX(), 2);
    EXPECT_EQ(center.getY(), 0);
}

TEST(RhombusTest, AreaCalculation) {
    std::vector<Point<int>> points = {
        Point<int>(1, 0),
        Point<int>(2, 2),
        Point<int>(3, 0),
        Point<int>(2, -2)
    };
    Rhombus<int> rhombus(points);
    double area = static_cast<double>(rhombus);
    EXPECT_NEAR(area, 4.0, 1e-6);
}

TEST(PentagonTest, CenterCalculation) {
    std::vector<Point<int>> points = {
        Point<int>(0, 0),
        Point<int>(2, 0),
        Point<int>(3, 2),
        Point<int>(1, 4),
        Point<int>(-1, 2)
    };
    Pentagon<int> pentagon(points);
    Point<int> center = pentagon.center();
    EXPECT_EQ(center.getX(), 1);
    EXPECT_EQ(center.getY(), 1);
}

TEST(PentagonTest, AreaCalculation) {
    std::vector<Point<int>> points = {
        Point<int>(0, 0),
        Point<int>(2, 0),
        Point<int>(3, 2),
        Point<int>(1, 4),
        Point<int>(-1, 2)
    };
    Pentagon<int> pentagon(points);
    double area = static_cast<double>(pentagon);
    EXPECT_NEAR(area, 8.0, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
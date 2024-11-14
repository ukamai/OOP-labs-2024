#include <gtest/gtest.h>
#include "../include/Twelve.h"

// Тест конструктора по умолчанию
TEST(TwelveTest, DefaultConstructor) {
    Twelve num;
    EXPECT_EQ(num.toString(), "0");
}

// Тест конструктора из строки
TEST(TwelveTest, StringConstructor) {
    Twelve num("1A2B");
    EXPECT_EQ(num.toString(), "1A2B");
}

// Тест копирующего конструктора
TEST(TwelveTest, CopyConstructor) {
    Twelve num1("1A2B");
    Twelve num2(num1);
    EXPECT_EQ(num2.toString(), "1A2B");
}

// Тест перемещающего конструктора
TEST(TwelveTest, MoveConstructor) {
    Twelve num1("1A2B");
    Twelve num2(std::move(num1));
    EXPECT_EQ(num2.toString(), "1A2B");
}

// Тест оператора присваивания копированием
TEST(TwelveTest, CopyAssignmentOperator) {
    Twelve num1("1A2B");
    Twelve num2;
    num2 = num1;
    EXPECT_EQ(num2.toString(), "1A2B");
}

// Тест оператора присваивания перемещением
TEST(TwelveTest, MoveAssignmentOperator) {
    Twelve num1("1A2B");
    Twelve num2;
    num2 = std::move(num1);
    EXPECT_EQ(num2.toString(), "1A2B");
}

// Тест оператора сложения
TEST(TwelveTest, AdditionOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    Twelve result = num1 + num2;
    EXPECT_EQ(result.toString(), "2174");
}

// Тест оператора вычитания
TEST(TwelveTest, SubtractionOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    Twelve result = num1 - num2;
    EXPECT_EQ(result.toString(), "16A6");
}

// Тест оператора сложения с присваиванием
TEST(TwelveTest, AdditionAssignmentOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    num1 += num2;
    EXPECT_EQ(num1.toString(), "2174");
}

// Тест оператора вычитания с присваиванием
TEST(TwelveTest, SubtractionAssignmentOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    num1 -= num2;
    EXPECT_EQ(num1.toString(), "16A6");
}

// Тест оператора сравнения на равенство
TEST(TwelveTest, EqualityOperator) {
    Twelve num1("1A2B");
    Twelve num2("1A2B");
    EXPECT_TRUE(num1 == num2);
}

// Тест оператора сравнения на неравенство
TEST(TwelveTest, InequalityOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    EXPECT_TRUE(num1 != num2);
}

// Тест оператора сравнения "меньше"
TEST(TwelveTest, LessThanOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    EXPECT_TRUE(num2 < num1);
}

// Тест оператора сравнения "больше"
TEST(TwelveTest, GreaterThanOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    EXPECT_TRUE(num1 > num2);
}

// Тест оператора сравнения "меньше или равно"
TEST(TwelveTest, LessThanOrEqualOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    EXPECT_TRUE(num2 <= num1);
}

// Тест оператора сравнения "больше или равно"
TEST(TwelveTest, GreaterThanOrEqualOperator) {
    Twelve num1("1A2B");
    Twelve num2("345");
    EXPECT_TRUE(num1 >= num2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

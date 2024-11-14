#ifndef TWELVE_H
#define TWELVE_H

#include <iostream>
#include <stdexcept>
#include <string>

class Twelve {
public:
    // Конструкторы
    Twelve();
    Twelve(const std::string& num);
    Twelve(const Twelve& other);
    Twelve(Twelve&& other) noexcept;
    ~Twelve() noexcept;

    // Операторы присваивания
    Twelve& operator=(const Twelve& other);
    Twelve& operator=(Twelve&& other) noexcept;

    // Арифметические операции
    Twelve operator+(const Twelve& other) const;
    Twelve operator-(const Twelve& other) const;
    Twelve& operator+=(const Twelve& other);
    Twelve& operator-=(const Twelve& other);

    // Операции сравнения
    bool operator==(const Twelve& other) const;
    bool operator!=(const Twelve& other) const;
    bool operator<(const Twelve& other) const;
    bool operator>(const Twelve& other) const;
    bool operator<=(const Twelve& other) const;
    bool operator>=(const Twelve& other) const;

    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const Twelve& num);
    friend std::istream& operator>>(std::istream& is, Twelve& num);

    // Публичный метод для доступа к toString
    std::string toString() const;

private:
    unsigned char* digits;  // Массив цифр числа
    size_t size;            // Размер массива

    // Вспомогательные методы
    void normalize();  // Нормализация числа (удаление ведущих нулей)
    void fromString(const std::string& num);  // Преобразование строки в число
    void resize(size_t newSize);  // Изменение размера массива
};

#endif // TWELVE_H

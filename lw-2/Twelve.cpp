#include "Twelve.h"

// Конструктор по умолчанию
Twelve::Twelve() : digits(new unsigned char[1]), size(1) {
    digits[0] = 0;
}

// Конструктор из строки
Twelve::Twelve(const std::string& num) : digits(nullptr), size(0) {
    fromString(num);
}

// Конструктор копирования
Twelve::Twelve(const Twelve& other) : digits(new unsigned char[other.size]), size(other.size) {
    for (size_t i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
}

// Конструктор перемещения
Twelve::Twelve(Twelve&& other) noexcept : digits(other.digits), size(other.size) {
    other.digits = nullptr;
    other.size = 0;
}

// Деструктор
Twelve::~Twelve() noexcept {
    delete[] digits;
}

// Оператор присваивания копированием
Twelve& Twelve::operator=(const Twelve& other) {
    if (this != &other) {
        delete[] digits;
        digits = new unsigned char[other.size];
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }
    }
    return *this;
}

// Оператор присваивания перемещением
Twelve& Twelve::operator=(Twelve&& other) noexcept {
    if (this != &other) {
        delete[] digits;
        digits = other.digits;
        size = other.size;
        other.digits = nullptr;
        other.size = 0;
    }
    return *this;
}

// Оператор сложения
Twelve Twelve::operator+(const Twelve& other) const {
    Twelve result;
    result.resize(std::max(size, other.size) + 1);

    int carry = 0;
    for (size_t i = 0; i < result.size; ++i) {
        int sum = carry;
        if (i < size) sum += digits[i];
        if (i < other.size) sum += other.digits[i];

        result.digits[i] = sum % 12;
        carry = sum / 12;
    }

    result.normalize();
    return result;
}

// Оператор вычитания
Twelve Twelve::operator-(const Twelve& other) const {
    if (*this < other) {
        throw std::invalid_argument("Result of subtraction is negative");
    }

    Twelve result;
    result.resize(size);

    int borrow = 0;
    for (size_t i = 0; i < result.size; ++i) {
        int diff = digits[i] - borrow;
        if (i < other.size) diff -= other.digits[i];

        if (diff < 0) {
            diff += 12;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digits[i] = diff;
    }

    result.normalize();
    return result;
}

// Оператор сложения с присваиванием
Twelve& Twelve::operator+=(const Twelve& other) {
    *this = *this + other;
    return *this;
}

// Оператор вычитания с присваиванием
Twelve& Twelve::operator-=(const Twelve& other) {
    *this = *this - other;
    return *this;
}

// Оператор сравнения на равенство
bool Twelve::operator==(const Twelve& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

// Оператор сравнения на неравенство
bool Twelve::operator!=(const Twelve& other) const {
    return !(*this == other);
}

// Оператор сравнения "меньше"
bool Twelve::operator<(const Twelve& other) const {
    if (size != other.size) {
        return size < other.size;
    }
    for (size_t i = size; i > 0; --i) {
        if (digits[i - 1] != other.digits[i - 1]) {
            return digits[i - 1] < other.digits[i - 1];
        }
    }
    return false;
}

// Оператор сравнения "больше"
bool Twelve::operator>(const Twelve& other) const {
    return other < *this;
}

// Оператор сравнения "меньше или равно"
bool Twelve::operator<=(const Twelve& other) const {
    return !(*this > other);
}

// Оператор сравнения "больше или равно"
bool Twelve::operator>=(const Twelve& other) const {
    return !(*this < other);
}

// Вывод числа в поток
std::ostream& operator<<(std::ostream& os, const Twelve& num) {
    os << num.toString();
    return os;
}

// Ввод числа из потока
std::istream& operator>>(std::istream& is, Twelve& num) {
    std::string input;
    is >> input;
    num.fromString(input);
    return is;
}

// Нормализация числа (удаление ведущих нулей)
void Twelve::normalize() {
    while (size > 1 && digits[size - 1] == 0) {
        --size;
    }
    unsigned char* newDigits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        newDigits[i] = digits[i];
    }
    delete[] digits;
    digits = newDigits;
}

// Преобразование строки в число
void Twelve::fromString(const std::string& num) {
    size = num.size();
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        char c = num[size - 1 - i];
        if (c >= '0' && c <= '9') {
            digits[i] = c - '0';
        } else if (c >= 'A' && c <= 'B') {
            digits[i] = c - 'A' + 10;
        } else {
            throw std::invalid_argument("Invalid character in input string");
        }
    }
    normalize();
}

// Преобразование числа в строку
std::string Twelve::toString() const {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        if (digits[size - 1 - i] < 10) {
            result += (digits[size - 1 - i] + '0');
        } else {
            result += (digits[size - 1 - i] - 10 + 'A');
        }
    }
    return result;
}

// Изменение размера массива
void Twelve::resize(size_t newSize) {
    unsigned char* newDigits = new unsigned char[newSize];
    size_t minSize = std::min(size, newSize);
    for (size_t i = 0; i < minSize; ++i) {
        newDigits[i] = digits[i];
    }
    for (size_t i = minSize; i < newSize; ++i) {
        newDigits[i] = 0;
    }
    delete[] digits;
    digits = newDigits;
    size = newSize;
}

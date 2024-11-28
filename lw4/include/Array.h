#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>

template <typename T>
class Array {
public:
    Array() : data(nullptr), array_size(0), capacity(0) {}
    ~Array() { delete[] data; }

    void push_back(const T& value) {
        if (array_size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        new (&data[array_size]) T(value);
        array_size++;
    }

    void erase(size_t index) {
        if (index >= array_size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < array_size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        array_size--;
    }

    size_t size() const { return array_size; }

    T& operator[](size_t index) {
        if (index >= array_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

private:
    void resize(size_t newCapacity) {
        if (newCapacity == capacity) return;
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < array_size; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    T* data;
    size_t array_size;
    size_t capacity;
};

#endif // ARRAY_H
#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include <memory_resource>
#include <iterator>

template <typename T>
class CustomList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

public:
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer operator->() const { return &current->data; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }

    private:
        Node* current;
    };

    CustomList(std::pmr::polymorphic_allocator<Node> alloc = std::pmr::get_default_resource())
        : allocator(alloc), head(nullptr), tail(nullptr) {}

    ~CustomList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            allocator.destroy(temp);
            allocator.deallocate(temp, 1);
        }
    }

    void push_back(const T& value) {
        Node* newNode = allocator.allocate(1);
        allocator.construct(newNode, value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

private:
    std::pmr::polymorphic_allocator<Node> allocator;
    Node* head;
    Node* tail;
};

#endif // CUSTOMLIST_H

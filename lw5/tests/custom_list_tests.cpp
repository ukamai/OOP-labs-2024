#include <gtest/gtest.h>
#include <memory_resource>
#include "CustomMemoryResource.h"
#include "CustomList.h"

TEST(CustomMemoryResourceTest, BasicAllocationAndDeallocation) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    int* ptr1 = alloc.allocate(1);
    alloc.construct(ptr1, 42);
    EXPECT_EQ(*ptr1, 42);

    int* ptr2 = alloc.allocate(1);
    alloc.construct(ptr2, 100);
    EXPECT_EQ(*ptr2, 100);

    alloc.destroy(ptr1);
    alloc.deallocate(ptr1, 1);

    alloc.destroy(ptr2);
    alloc.deallocate(ptr2, 1);
}

TEST(CustomListTest, IntListOperations) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    CustomList<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    int expected[] = {1, 2, 3};
    int i = 0;
    for (auto it = intList.begin(); it != intList.end(); ++it) {
        EXPECT_EQ(*it, expected[i++]);
    }
}

struct ComplexType {
    int a;
    double b;
    std::string c;

    ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
};

TEST(CustomListTest, ComplexTypeListOperations) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<ComplexType> alloc(&memRes);

    CustomList<ComplexType> complexList(alloc);
    complexList.push_back(ComplexType(1, 1.1, "one"));
    complexList.push_back(ComplexType(2, 2.2, "two"));
    complexList.push_back(ComplexType(3, 3.3, "three"));

    ComplexType expected[] = {
        {1, 1.1, "one"},
        {2, 2.2, "two"},
        {3, 3.3, "three"}
    };
    int i = 0;
    for (auto it = complexList.begin(); it != complexList.end(); ++it) {
        EXPECT_EQ(it->a, expected[i].a);
        EXPECT_EQ(it->b, expected[i].b);
        EXPECT_EQ(it->c, expected[i].c);
        ++i;
    }
}

TEST(CustomListTest, EmptyList) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    CustomList<int> intList(alloc);
    EXPECT_EQ(intList.begin(), intList.end());
}

TEST(CustomListTest, SingleElementList) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    CustomList<int> intList(alloc);
    intList.push_back(42);

    auto it = intList.begin();
    EXPECT_EQ(*it, 42);
    EXPECT_EQ(++it, intList.end());
}

TEST(CustomListTest, AddAndRemoveElements) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    CustomList<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    int expected[] = {1, 2, 3};
    int i = 0;
    for (auto it = intList.begin(); it != intList.end(); ++it) {
        EXPECT_EQ(*it, expected[i++]);
    }

}

TEST(CustomListTest, CopyList) {
    CustomMemoryResource memRes;
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    CustomList<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

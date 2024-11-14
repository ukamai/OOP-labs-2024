#ifndef CUSTOMMEMORYRESOURCE_H
#define CUSTOMMEMORYRESOURCE_H

#include <memory_resource>
#include <list>
#include <cstddef>

class CustomMemoryResource : public std::pmr::memory_resource {
public:
    CustomMemoryResource() = default;
    ~CustomMemoryResource() override;

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    struct MemoryBlock {
        void* ptr;
        std::size_t size;
    };

    std::list<MemoryBlock> allocatedBlocks;
    std::list<MemoryBlock> freeBlocks;
};

#endif // CUSTOMMEMORYRESOURCE_H

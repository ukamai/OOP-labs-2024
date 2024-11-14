#include "CustomMemoryResource.h"
#include <cstdlib>
#include <algorithm>

CustomMemoryResource::~CustomMemoryResource() {
    for (const auto& block : allocatedBlocks) {
        std::free(block.ptr);
    }
}

void* CustomMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    // Поиск подходящего свободного блока
    auto it = std::find_if(freeBlocks.begin(), freeBlocks.end(), [&](const MemoryBlock& block) {
        return block.size >= bytes;
    });

    if (it != freeBlocks.end()) {
        void* ptr = it->ptr;
        freeBlocks.erase(it);
        return ptr;
    }

    // Выделение нового блока
    void* ptr = std::aligned_alloc(alignment, bytes);
    if (!ptr) {
        throw std::bad_alloc();
    }

    allocatedBlocks.push_back({ptr, bytes});
    return ptr;
}

void CustomMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    // Поиск блока в выделенных блоках
    auto it = std::find_if(allocatedBlocks.begin(), allocatedBlocks.end(), [&](const MemoryBlock& block) {
        return block.ptr == p;
    });

    if (it != allocatedBlocks.end()) {
        freeBlocks.push_back({p, bytes});
    } else {
        std::free(p);
    }
}

bool CustomMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

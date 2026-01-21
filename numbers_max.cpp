#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sys/mman.h>

extern unsigned char _binary_large_data_start[];
extern unsigned char _binary_large_data_end[];

static const int32_t* numbers = reinterpret_cast<const int32_t*>(_binary_large_data_start);

int main() {
    size_t size = _binary_large_data_end - _binary_large_data_start;
    std::cout << "Size: " << size << " bytes" << std::endl;

    int32_t max = numbers[0];
    for (int i = 1; i < 100000; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    std::cout << "Max: " << max << std::endl;

    // Evict large_data pages from RSS
    void* page_start = (void*)((uintptr_t)_binary_large_data_start & ~4095UL);
    size_t page_size = _binary_large_data_end - (unsigned char*)page_start;
    madvise(page_start, page_size, MADV_DONTNEED);

    return 0;
}

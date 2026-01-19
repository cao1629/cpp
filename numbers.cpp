#include <cstdint>
#include <iostream>


extern unsigned char _binary_data_start[];

static const int32_t* numbers = reinterpret_cast<const int32_t*>(_binary_data_start);

int main() {
    int64_t sum = 0;
    for (int i = 0; i < 1000; ++i) {
        sum += numbers[i];
    }
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

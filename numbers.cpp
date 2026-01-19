#include <cstdint>

// Embedded binary data (generated from 'data' file)
extern unsigned char data[];

// Global static pointer to the 1000 numbers
static const int32_t* numbers = reinterpret_cast<const int32_t*>(data);

#include <stdio.h>

// why we shouldn't use extern char* data
// compiler would think "data" is a pointer variable, not an array.
// A point is only 8 bytes.
extern char data[];

int main() {
    printf("%d\n", data[2]);
}

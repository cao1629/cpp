#include <stdio.h>


int main() {
    char data1[] = {0xFF, 0xFE, 0xFD, 0xFC};
    unsigned char data2[] = {0xFF, 0xFE, 0xFD, 0xFC};
    char data3[] = {65, 66, 67, 68, 69};
    int byte1 = data1[0];
    int byte2 = data2[0];
    printf("%d\n", byte1);
    printf("%d\n", byte2);
}
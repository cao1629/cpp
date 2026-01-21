
#include <stdio.h>
#include <string.h>


int main() {
    char ss[][4] = {"AAA", "BBB", "CCC"};
    memcpy(ss[0], "DDD", 4);
    printf("%s\n", ss[0]);
}
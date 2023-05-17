#include <stdio.h>
#include <malloc.h>
#include <inttypes.h>

int main() {
    int size = sizeof(int64_t);
    int *ptr = malloc(sizeof(int) * 10);
    printf("%i\n", size);
    printf("%x\n", *ptr);
    return 0;
}

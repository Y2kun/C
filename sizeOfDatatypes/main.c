#include <stdio.h>
#include <malloc.h>

int main() {
    int *ptr = malloc(sizeof(int) * 10);
    printf("%x", *ptr);

    return 0;
}

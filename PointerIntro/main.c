#include <stdio.h>

void fkt(int*);

int main() {
    int x = 12;
    printf("The Value of x = %i\n", x);

    fkt(&x);

    printf("The Value of x = %i\n", x);
    return 0;
}

void fkt(int *ptr) {
    *ptr = 1000;
}
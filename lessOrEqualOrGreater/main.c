#include <stdio.h>

int main() {
    int a = 0 ,b = 0;

    printf("Please input two numbers ");
    scanf("%i %i", &a, &b);

    if (a == b) {printf("%i == %i\n", a, b);}
    else if (a > b) {printf("%i > %i\n", a, b);}
    else if (a >= b) {printf("%i >= %i\n", a, b);}
    else if (a < b) {printf("%i < %i\n", a, b);}
    else if (a <= b) {printf("%i <= %i", a, b);}
    return 0;
}

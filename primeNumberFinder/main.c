#include <stdio.h>

//Does not work for all numbers!!!

int main() {
    int min = 0, max = 0;
    printf("Please input the minimum number, then the maximum number for finding the prime number: ");
    scanf("%i %i", &min, &max);

    for (int i = min; i <= max; i++) {
        if (i%2 && i%3 && i%4 && i%5 != 0) {
            printf("%i is a prime number\n", i);
        } else {
            printf("%i is not a prime number\n", i);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lr 100

int main() {
    srand(time(NULL));
    int rng = 0, i = 0, t = 0, sum = 0, smallest = lr, largest = 0;

    while(i < 3) {
        rng = rand() % lr + 1;
        if (rng == 6) {i++;}
        if (largest <= rng) {largest = rng;}
        if (smallest >= rng) {smallest = rng;}
        sum = sum + rng;
        t++;
    }
    printf("Number of times the d%i was rolled: %i\n", lr, t );
    printf("The largest number was: %i\n", largest);
    printf("The smallest number was: %i\n", smallest);
    printf("The sum of all the numbers was: %i\n", sum);
    return 0;
}

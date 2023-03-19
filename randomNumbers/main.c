#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 5000
#define MAX 1000
#define MIN 1

int main() {
    srand(time(NULL));
    int rng = 0, i = 0, sum = 0, max = MIN, min = MAX;

    while(i < X) {
        rng = rand() % MAX + MIN;
        if (max <= rng) {max = rng;}
        if (min >= rng) {min = rng;}
        sum = sum + rng;
        i++;
    }
    printf("Maximum: %i\n", max);
    printf("Minimum: %i\n", min);
    printf("Average: %i\n", sum/X);
    return 0;
}

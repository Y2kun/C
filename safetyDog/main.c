#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int rng = 0, t = 0, min = 60, max = 0, war = 0;
    while(t <= 60) {
        rng = rand() % 60;
        printf("%i: %i\n", t, rng);
        if (rng > 40) {
            printf("WARNING: CRITICAL CORETEMPERATURE!!!\n");
            war++;
        }
        if (min > rng) {min = rng;}
        if (max < rng) {max = rng;}
        t++;
    }
    printf("Minimal Temperature: %i\nMaximal Temperature: %i\nWarning amount: %i\n", min, max, war);
    return 0;
}

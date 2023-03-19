#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((time(NULL)));
    int place = 0, step = 0, i = 0, min = 0;
    printf("The drunk person leaves the inn and goes home\n");
    while (place < 8 && place > -7 && i < 50) {
        int rng = rand() % 2;
        if (rng == 0) {place--;};
        if (rng == 1) {place++;};
        if (min >= place) {min = place;};
        printf("%i ", place);
        i++;
    }

    if (i == 50) {printf("\nThe drunk person passed out on the street.");}
    if (place >= 8) {printf("\nThe drunk person got home.");}
    if (place <= -7) {printf("\nThe drunk person fell into the lake.");}
    printf("\nThe drunk person was %i step(s) away from the lake.", min+7);
    return 0;
}
